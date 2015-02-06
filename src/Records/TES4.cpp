#include <iostream>
#include <string.h>
#include <list>

#include "TES4.hpp"
#include "../SubRecord.hpp"
#include "../Reader.hpp"

using namespace std;
bool RecordTES4::DoParse()
{

    std::string subType = GetLabel();
    
    if (subType == "HEDR")
    {
        data.hedr.version = GetData<float>();
        data.hedr.numRecords = GetData<uint32_t>();
        data.hedr.nextObjID = GetData<uint32_t>();
    }
    else if (subType == "OFST" || subType == "DELE" || subType == "SCRN")
        IgnoreBytes(subhead.dataSize);
    else if (subType == "CNAM")
        data.author = GetString();
    else if (subType == "SNAM")
        data.description = GetString();
    else if (subType == "MAST") // need it in cycle
    { 
        std::string master = GetString();
        data.masters.push_back(master);
        IgnoreBytes(14); // SubRecord DATA (obsolete) 14 = header + uint64_t data
    }
    else if (subType == "ONAM")
    {
        uint32_t formid =  GetData<uint32_t>();
        data.formOverrides.push_back(formid);
    }
    else return false;
    return true;
}
