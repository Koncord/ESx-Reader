/* 
 * File:   ALCH.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 4 Февраль 2015 г., 23:47
 */

#include "ALCH.hpp"


bool RecordALCH::DoParse()
{
    std::string subType = GetLabel();
    
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "FULL")
        data.name = GetString();
    else if(ModelCollection()) {}
    else if(subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if(subType == "SCRI")
        data.scriptId = GetData<formid>();
    else if(DestructionData(&data.destruction)) {}
    else if(subType == "YNAM" || subType == "ZNAM")
        IgnoreSubRecord();
    else if(subType == "ETYP")
        data.equipmentType.equipType = GetData<uint32_t>();
    else if(subType == "DATA")
        data.weight = GetData<float>();
    else if(subType == "ENIT")
        data.effectData = GetData<DATA::ENIT>();
    else if(EffectCollection(&data.effect)) {}
    else return false;
    return true;
}
