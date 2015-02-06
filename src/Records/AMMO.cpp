/* 
 * File:   AMMO.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 1 Февраль 2015 г., 1:40
 */

#include"AMMO.hpp"

bool RecordAMMO::DoParse()
{
    std::string subType = GetLabel();
    if(subType == "EDID")
    {
        data.edid = GetString();
    }
    else if(subType == "OBND")
    {
        data.obnd = GetData<DATA::OBND>();
    }
    else if(subType == "FULL")
    {
        data.name = GetString();
    }
    else if(subType == "ONAM")
    {
        data.shortName = GetString();
    }
    else if(subType == "DATA")
    {
        data.data = GetData<DATA::_DATA>();
    }
    else if(SkipModelData()) {}
    else if(DestructionData(&data.destruction)) {}
    else if(subType == "ICON" || subType == "MICO" || subType == "YNAM" || subType == "ZNAM")
        IgnoreSubRecord(); // ignore icons and sounds;
    else return false;
    return true;
}
