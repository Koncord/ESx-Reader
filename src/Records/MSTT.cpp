/* 
 * File:   MSTT.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 15:25
 */

#include "MSTT.hpp"

using namespace std;

bool RecordMSTT::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "DATA")
        data.unknown = GetData<uint8_t>();
    else if(subType == "SNAM")
        data.sound = GetData<formid>();
    else if(DestructionData(&data.destruction)) {}
    else if(ModelCollection()) {}
    else return false;
    return true;
}
