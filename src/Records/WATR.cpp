/* 
 * File:   WATR.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 17 Апрель 2015 г., 15:46
 */

#include "WATR.hpp"

using namespace std;

bool RecordWATR::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "FNAM")
        data.flags = GetData<uint8_t>();
    else if(subType == "SNAM")
        data.sound = GetData<formid>();
    else if(subType == "XNAM")
        data.actorEffect = GetData<formid>();
    else if(subType == "DATA" || subType == "DNAM")
    {
        if(subhead.dataSize > sizeof(uint16_t))
            IgnoreBytes(subhead.dataSize -  sizeof(uint16_t));
        data.actorEffect = GetData<uint16_t>();
    }
    else if(subType == "NNAM" || subType == "ANAM" || subType == "MNAM" ||
            subType == "DATA" || subType == "GNAM")
        IgnoreSubRecord();
    else return false;
    return true;
}
