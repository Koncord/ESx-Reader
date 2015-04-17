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
    static bool fData = true;
    string subType = GetLabel();
    if(subType == "EDID")
    {
        fData = true;
        data.edid = GetString();
    }
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "FNAM")
        data.flags = GetData<uint8_t>();
    else if(subType == "SNAM")
        data.sound = GetData<formid>();
    else if(subType == "XNAM")
        data.actorEffect = GetData<formid>();
    else if(subType == "DATA" && fData)
    {
        fData = false;
        data.actorEffect = GetData<uint16_t>();
    }
    else if(subType == "NNAM" || subType == "ANAM" || subType == "MNAM" ||
            subType == "DATA" || subType == "DNAM" || subType == "GNAM")
        IgnoreSubRecord();
    else return false;
    return true;
}
