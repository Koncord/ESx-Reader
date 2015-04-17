/* 
 * File:   IDLE.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 12 Апрель 2015 г., 17:38
 */

#include "IDLE.hpp"

using namespace std;

bool RecordIDLE::DoParse()
{
    static CTDA condition;
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(ConditionsData(&condition))
        data.conditions.push_back(condition);
    else if(subType == "ANAM")
        data.releatedIdleAnimations.push_back(GetData<formid>());
    else if(ModelCollection()) {}
    else return false;
    return true;
}
