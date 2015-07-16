#include "Record.hpp"
#include "Reader.hpp"
#include <iostream>
#include <zlib.h>

#include <sstream>
#include <iomanip>

using namespace std;

int32_t uncompressRecord(uint8_t *dest, uint32_t dsize, uint8_t *source, uint32_t ssize)
{
    int32_t code;
    z_stream strm;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    
    if((code = inflateInit(&strm)) != Z_OK)
        return code;
    
    strm.avail_in = ssize;
    strm.next_in = source;
    
    strm.avail_out = dsize;
    strm.next_out = dest;

    code = inflate(&strm, Z_NO_FLUSH);
    
    inflateEnd(&strm);

    return code == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

void Record::ParseHead(const RecHeader &head)
{
    Reader *reader = Reader::GetSelf();
    this->head = head;
    
    rawdata.pos = rawdata.size = 0;
    if(GetFlag(Flag::isCompressed))
    {
        // unpack
        std::unique_ptr <uint8_t[]> compData(new uint8_t[head.dataSize - 4]);
        uint32_t decompSize;
        reader->ReadData((uint8_t*)&decompSize, 4);
        rawdata.data.reset(new uint8_t[decompSize]);

        reader->ReadData (compData.get(), head.dataSize - 4);

        uncompressRecord(rawdata.data.get(), decompSize, compData.get(), head.dataSize - 4);
        rawdata.size = decompSize;
    }
    else
    {
        rawdata.data.reset(new uint8_t[head.dataSize]);
        
        reader->ReadData (rawdata.data.get(), head.dataSize);
        
        rawdata.size = head.dataSize;
    }
}

Record::~Record()
{

}

RecHeader Record::ReadHeader()
{
    RecHeader head;
    Reader::GetSelf()->ReadData((uint8_t*)&head, sizeof(RecHeader));
    return head;
}

void Record::Parse()
{
    while (rawdata.pos < rawdata.size)
    {
#ifdef _DEVMESSAGES
        const SubRecHeader prevSubHead = subhead;
        const uint32_t prevOffset = rawdata.pos - sizeof (SubRecHeader) - subhead.dataSize;
        const uint32_t prevPos = rawdata.pos;
#endif
        
        ReadSubHeader();
        if(string(subhead.type, 4) == "XXXX")
            IgnoreSubRecord();
        else if (!DoParse())
        {
            stringstream sstr;
            sstr << std::uppercase << std::setfill('0') << std::setw(4) << head.id;
            string filename = string(head.type, 4) + "_" + sstr.str();
            sstr.str("");
            ofstream frec(filename + ".rec");
            frec.write((char*) rawdata.data.get(), rawdata.size);
            frec.close();
            ofstream log(filename + ".txt", ofstream::ate);
            
            sstr << "In record: " + string(head.type, 4)
                    << " detected an unknown subrecord: " << string(subhead.type, 4) << endl
                    << "Size of subrecord: " << subhead.dataSize << endl
                    /*<< "Global offset: "
                    << to_string((uint32_t) (Reader::GetSelf()->file.tellg()) - head.dataSize + rawdata.pos - sizeof (SubRecHeader)) << endl*/
                    << "Offset in record: " << to_string(rawdata.pos - sizeof (SubRecHeader)) << endl;
#ifdef _DEVMESSAGES
                    sstr << "Previous subrecord: " << string(prevSubHead.type, 4) << endl
                    << "Size of subrecord: " << prevSubHead.dataSize <<  " expected: " << rawdata.pos -  prevPos << endl
                    << "Offset in record: " << prevOffset << endl;
#endif
            log << sstr.str();
            log.close();
            throw runtime_error(sstr.str());
        }
    }
}

void Record::ReadSubHeader()
{
    subhead = SubRecord::ReadHeader(rawdata.data.get(), &rawdata.pos);
}

Record::Record(const RecHeader &head)
{
    ParseHead(head);
}

Record::Record()
{
    head = Record::ReadHeader();
    ParseHead(head);
}