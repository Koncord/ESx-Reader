/* 
 * File:   SCOL.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 15:15
 */

#include "SCOL.hpp"

using namespace std;

bool RecordSCOL::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(ModelCollection()) {}
    // -------------------------- Part Subrecord Collection---------------------
    else if(subType == "ONAM")
    {
        data.parts.push_back(DATA::Part());
        data.parts.back()._static = GetData<formid>();
    }
    else if(subType == "DATA")
    {
        uint16_t tmp = subhead.dataSize;
        do
            data.parts.back().placements.push_back(GetData<DATA::Part::Placement>());
        while(tmp -= sizeof(DATA::Part::Placement));
    }
    // -------------------------------------------------------------------------
    else return false;
    return true;
}