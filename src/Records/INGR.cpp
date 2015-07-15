/* 
 * File:   INGR.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 20:25
 */

#include "INGR.hpp"

using namespace std;

bool RecordINGR::DoParse()
{
    static Effect effect;
    TODO( need to implement the Effect collection )
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if (subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if (subType == "SCRI") 
        data.script = GetData<formid>();
    else if (subType == "ETYP")
        data.equipmentType = GetData<int32_t>();
    else if (subType == "DATA")
        data.weight = GetData<float>();
    else if (subType == "ENIT")
        data.effectData = GetData<DATA::EffectData>();
    else if (EffectCollection(&effect))
        data.effects.push_back(effect);
        
    else if(ModelCollection()) {}
    else return false;
    return true;
}
