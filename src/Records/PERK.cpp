/* 
 * File:   PERK.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 18:35
 */

#include "PERK.hpp"

using namespace std;

bool RecordPERK::DoParse()
{
    TODO(implement Effect Collection like Menu Item Subrecord Collection)
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(SkipModelData()) {}
    else if(subType == "MICO" || subType == "ICON") 
        IgnoreSubRecord();
    else if(subType == "DESC")
        data.description = GetString();
    else if(subType == "DATA")
    {
        data.data = GetData<DATA::_DATA>();
    }
    else if(ConditionsData(&data.conditions)) { }
    else return false;
    return true;
}
