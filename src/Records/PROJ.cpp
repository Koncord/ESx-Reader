/* 
 * File:   PROJ.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 21:27
 */

#include "PROJ.hpp"

using namespace std;

bool RecordPROJ::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(subType == "NAM1" || subType == "NAM2")
        IgnoreSubRecord();
    else if(subType == "VNAM")
        data.soundLevel = GetData<uint32_t>();
    else if(DestructionData(&data.destruction)) {}
    else if(ModelCollection()) {}
    else return false;
    return true;
}
