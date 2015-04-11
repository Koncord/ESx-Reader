/* 
 * File:   SPEL.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 0:37
 */

#include "SPEL.hpp"

using namespace std;

bool RecordSPEL::DoParse()
{
    Effect effect;
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "SPIT")
        data.data = GetData<DATA::_DATA>();
    else if(EffectCollection(&effect))
        data.effects.push_back(effect);
    else return false;
    return true;
}
