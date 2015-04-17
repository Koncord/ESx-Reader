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
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "IDLF")
        data.flags = GetData<uint8_t>();
    else if(subType == "IDLC")
        data.animationCount = GetData<uint32_t>();
    else if(subType == "IDLT")
        data.idleTimerSetting = GetData<float>();
    else if(subType == "IDLA")
        data.animation.push_back(GetData<uint32_t>());
    else return false;
    return true;
}