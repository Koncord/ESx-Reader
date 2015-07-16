/* 
 * File:   CELL.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 17:03
 */

#include "CELL.hpp"

using namespace std;

bool RecordCELL::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "DATA")
        data.flags = GetData<uint8_t>();
    else if(subType == "XCLC")
        data.grid = GetData<DATA::Grid>(subhead.dataSize);
    else if(subType == "XCLL")
        data.lighting = GetData<DATA::Lighting>(subhead.dataSize);
    else if(subType == "IMPF") // Unknown format
        IgnoreSubRecord();
    else if(subType == "LTMP")
        data.lightTemplate.templateId = GetData<formid>();
    else if(subType == "LNAM")
        data.lightTemplate.inherit = GetData<uint32_t>();
    else if(subType == "XCLW")
        data.waterHeight = GetData<float>();
    else if(subType == "XNAM")
        IgnoreSubRecord();
    else if(subType == "XCLR")
    {
        uint16_t tmp = subhead.dataSize;
        do
            data.regions.push_back(GetData<formid>());
        while(tmp -= sizeof(formid));
    }
    else if(subType == "XCIM")
        IgnoreSubRecord();
    else if(subType == "XCET") // Unknown
        IgnoreSubRecord();
    else if(subType == "XEZN")
        data.encounterZone = GetData<formid>();
    else if(subType == "XCCM")
        data.climate = GetData<formid>();
    else if(subType == "XCWT")
        data.water = GetData<formid>();
    else if(subType == "XOWN")
        data.owner = GetData<formid>();
    else if(subType == "XRNK")
        data.factionRank = GetData<int32_t>();
    else if(subType == "XCAS")
        IgnoreSubRecord();
    else if(subType == "XCMT") // Unused
        IgnoreSubRecord();
    else if(subType == "XCMO")
        IgnoreSubRecord();
    else return false;
    return true;
}