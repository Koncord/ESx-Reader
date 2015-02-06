/* 
 * File:   EXPL.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 6 Февраль 2015 г., 0:33
 */

#include "EXPL.hpp"

bool RecordEXPL::DoParse()
{
    std::string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.obnd = GetData<DATA::OBND>();
    else if(subType == "FULL")
        data.name = GetString();
    else if(SkipModelData()) {}
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
