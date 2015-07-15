/* 
 * File:   EXPL.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 6 Февраль 2015 г., 0:33
 */

#include "EXPL.hpp"

bool RecordEXPL::DoParse()
{
    const std::string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "FULL")
        data.name = GetString();
    else if(ModelCollection()) {}
    else if(subType == "EITM")
        data.objectEffectId = GetData<formid>();
    else if(subType == "MNAM")
        IgnoreSubRecord();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(subType == "INAM")
        data.placedImpactObject = GetData<formid>();
    else return false;
    return true;
}
