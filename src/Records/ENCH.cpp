/* 
 * File:   ENCH.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 22:20
 */

#include "ENCH.hpp"

using namespace std;

bool RecordENCH::DoParse()
{
    Effect effect;
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "ENIT")
        data.effectData = GetData<DATA::EffectData>();
    else if(EffectCollection(&effect))
        data.effects.push_back(effect);
    else return false;
    return true;
}
