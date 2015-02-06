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


bool Record::SkipModelData()
{
    std::string subType = GetLabel();
    if(
            subType == "MODL" || subType == "MODB" ||
            subType == "MODT" || subType == "MODS" ||
            subType == "MODD" || 
            subType == "MOD2" || subType == "MO2T" ||
            subType == "MO2S" ||
            subType == "MOD3" || subType == "MO3T" ||
            subType == "MO3S" || subType == "MOSD" ||
            subType == "MOD4" || subType == "MO4T" ||
            subType == "MO4S"
      )
    {
        IgnoreSubRecord();
        return true;
    }
    return false;
}

uint32_t damageCounter;

bool Record::DestructionData(DESTRUCTION *destruction)
{
    std::string subType = GetLabel();
    if(subType == "DEST")
    {
        #ifdef DEBUG
            //cerr << "WARNING! DestructionCollection is not fully implemented yet." << endl;
        #endif
        destruction->dest = GetData<DESTRUCTION::DEST>();
        destruction->dstages.reserve((uint32_t)destruction->dest.count);
        damageCounter = 0;
    }
    else if (subType == "DSTD")
        destruction->dstages[damageCounter++].dstd = GetData<DESTRUCTION::DSTAGE::DSTD>();
    else if(subType == "DMDL" || subType == "DMDT") // skip
        IgnoreSubRecord();
    else if(subType == "DSTF")
        IgnoreSubRecord(); // Destruction Stage End Marker (type = NULL)
    else
        return false;
    return true;
}

bool Record::ConditionsData(CTDA* cond)
{
    std::string subType = GetLabel();
    if(subType == "CTDA")
    {
        #ifdef DEBUG
            //cerr << "WARNING! CTDA is not fully implemented yet." << endl;
        #endif
        (*cond) = GetData<CTDA>(); 
    }
    else
        return false;
    return true;
}

bool Record::SubItemCollection(ITEMCOL* items)
{
    std::string subType = GetLabel();
    if(subType == "COED")
    {
        items->back().extra = GetData<ITEM::COED>(); 
    }
    else if(subType == "CNTO")
    {
        #ifdef DEBUG
            //cerr << "WARNING! SubItemCollection is not fully implemented yet." << endl;
        #endif
        items->push_back(ITEM());
        items->back().item = GetData<ITEM::CNTO>();
    }
    else
        return false;
    return true;
}

bool Record::ScriptCollection(SCRIPT* scr)
{
    std::string subType = GetLabel();
    if(subType == "SCHR")
        scr->main = GetData<SCRIPT::SCHR>();
    else if(subType == "SCDA")
    {
        scr->compiled.reserve(subhead.dataSize);
        for(int i = 0; i < subhead.dataSize; i++)
        {
            scr->compiled.push_back(GetData<uint8_t>());
        }
    }
    else if(subType == "SCTX")
        scr->source = GetString();
    else if(subType == "SCRO")
        scr->globRefs.push_back(GetData<formid>());
    else if(subType == "SLSD")
    {
        scr->localVariables.push_back(SCRIPT::LOCALVAR());
        scr->localVariables.back().data = GetData<SCRIPT::LOCALVAR::SLSD>();
    }
    else if(subType == "SCVR")
    {
        scr->localVariables.back().name = GetString();
    }
    else if(subType == "SCRV")
    {
        scr->locRefs.push_back(GetData<uint32_t>());
    }
    else return false;
    return true;
}

bool Record::EffectCollection(EFFECT* effect)
{
    string subType = GetLabel();
    if(subType == "EFID")
        effect->baseEffectId = GetData<formid>();
    else if(subType == "EFIT")
        effect->EffectData = GetData<EFFECT::EFIT>();
    else if(ConditionsData(&effect->condition)) {}
    else return false;
    return true;
}
