/* 
 * File:   ARMA.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 5 Февраль 2015 г., 15:32
 */

#include "ARMA.hpp"

bool RecordARMA::DoParse()
{
    std::string subType = GetLabel();
    if (subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<OBND>();
    else if (subType == "FULL")
        data.name = GetString();
    else if(subType == "BMDT")
        data.bipedData = GetData<BMDT>();
    else if(ModelCollection()) {}
    else if(subType == "ICON" || subType == "MICO" || subType == "ICO2" || subType == "MIC2")
        IgnoreSubRecord();
    else if(subType == "ETYP")
        data.equipmentType = GetData<ETYP>();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(subType == "DNAM")
        data.dnam = GetData<DATA::DNAM>();
    else return false;
    return true;
}
