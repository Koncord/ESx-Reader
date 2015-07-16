/* 
 * File:   IDLM.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 22:03
 */

#include "IDLM.hpp"

using namespace std;

bool RecordIDLM::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "IDLF")
        data.flags = GetData<uint8_t>();
    else if(subType == "IDLC")
    {
        const uint32_t tmp = rawdata.pos;
        data.animationCount = GetData<uint8_t>();
        GetData<uint8_t>(subhead.dataSize - (rawdata.pos - tmp));
    }
    else if(subType == "IDLT")
        data.idleTimerSetting = GetData<float>();
    else if(subType == "IDLA")
    {
        uint16_t tmp = subhead.dataSize;
        do
            data.animation.push_back(GetData<uint32_t>());
        while(tmp -= 4);
    }
    else return false;
    return true;
}