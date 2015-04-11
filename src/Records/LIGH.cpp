/* 
 * File:   LIGH.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 15:05
 */

#include "LIGH.hpp"

using namespace std;

bool RecordLIGH::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<OBND>();
    else if(ModelCollection()) {}
    else if (subType == "SCRI")
        data.script = GetData<formid>();
    else if(subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if(subType == "FMAM")
        data.fadeValue = GetData<float>();
    else if (subType == "SNAM")
        data.sound = GetData<formid>();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else return false;
    return true;
}