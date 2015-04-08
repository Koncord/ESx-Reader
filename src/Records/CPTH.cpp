/* 
 * File:   CPTH.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 20:43
 */

#include "CPTH.hpp"

using namespace std;

bool RecordCPTH::DoParse()
{
    CTDA condition;
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(ConditionsData(&condition))
        data.conditions.push_back(condition);
    else if(subType == "ANAM")
        data.relatedCameraPath.push_back(GetData<formid>());
    else if(subType == "DATA")
        data.cameraZoom = GetData<uint8_t>();
    else if(subType == "SNAM")
        data.cameraShot.push_back(GetData<formid>());
    else return false;
    return true;
}
