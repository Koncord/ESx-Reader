#include "Record.hpp"
#include "Reader.hpp"
#include <iostream>
#include <zlib.h>
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
        uint32_t decompSize = reader->ReadRaw<std::uint32_t>();
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
    return Reader::GetSelf()->ReadRaw<RecHeader>();
}

void Record::Parse()
{
    while (rawdata.pos < rawdata.size)
    {
        ReadSubHeader();
        if(!DoParse())
        {
            #ifdef DEBUG
            ofstream frec("failed.rec");
            frec.write((char*)rawdata.data.get(), rawdata.size);
            frec.close();
                Reader *reader = Reader::GetSelf();
                std::cerr << "WARNING! ";
                cerr << "Record: " << string(head.type, 4) <<  " unknown subrecord: " << string(subhead.type, 4);
                if(!GetFlag(Flag::isCompressed))
                    std::cerr << " global position: " << ((uint32_t)(reader->file.tellg())- head.dataSize  + rawdata.pos - sizeof(SubRecHeader));
                std::cerr << " local position: " << (rawdata.pos - sizeof(SubRecHeader)) << endl;
            #endif
                IgnoreSubRecord();
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