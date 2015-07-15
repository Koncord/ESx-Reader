/* 
 * File:   ARMO.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 5 Февраль 2015 г., 14:59
 */

#include "ARMO.hpp"

bool RecordARMO::DoParse()
{
    const std::string subType = GetLabel();
    if (subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if (subType == "FULL")
        data.name = GetString();
    else if(subType == "SCRI")
        data.scriptId = GetData<formid>();
    else if(subType == "EITM")
        data.objectEffectId = GetData<formid>();
    else if(subType == "BMDT")
        data.bipedData = GetData<BMDT>();
    else if(ModelCollection()) {}
    else if(subType == "ICON" || subType == "MICO" || subType == "ICO2" || subType == "MIC2")
        IgnoreSubRecord();
    else if(subType == "BMCT")
        data.ragdollConstTempl = GetString();
    else if(subType == "REPL")
        data.repairListId = GetData<formid>();
    else if(subType == "BIPL")
        data.bipedModelListId = GetData<formid>();
    else if(subType == "ETYP")
        data.equipmentType = GetData<ETYP>();
    else if(subType == "YNAM" || subType == "ZNAM")
        IgnoreSubRecord();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(subType == "DNAM")
        data.dnam = GetData<DATA::DNAM>();
    else return false;
    return true;
}
