/* 
 * File:   WRLD.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 2 Июль 2015 г., 14:44
 */

#include "WRLD.hpp"

using namespace std;

bool RecordWRLD::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "XEZN")
        data.encounterZoneId = GetData<formid>();
    else if(subType == "WNAM")
        data.parentWorldspaceId = GetData<formid>();
    else if(subType == "PNAM")
        data.parentWorldspaceFlags = GetData<DATA::ParentWorldspaceFlags>();
    else if(subType == "CNAM")
        data.climateId = GetData<formid>();
    else if(subType == "NAM2")
        data.waterId = GetData<formid>();
    else if(subType == "DATA")
        data.flags = GetData<uint8_t>();
    else if(subType == "NAM3" || subType == "NAM4" || subType == "DNAM" || subType == "ICON" || subType == "MICO" || subType == "ONAM" || 
            subType == "INAM" || subType == "NAM0" || subType == "NAM9" || subType == "ZNAM" || subType == "NNAM" || subType == "XNAM" ||
            subType == "IMPS" || subType == "IMPF" || subType == "MNAM")
        IgnoreSubRecord();
    else if(subType == "OFST") // WUUT IS IT?!
        rawdata.pos = rawdata.size; // hack
    else return false;
    return true;
}