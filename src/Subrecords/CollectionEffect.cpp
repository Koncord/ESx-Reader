/* 
 * File:   CollectionEffect.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 20:52
 */

#include "CollectionEffect.hpp"
#include "../Record.hpp"

bool Record::EffectCollection(Effect* effect)
{
    const std::string subType = GetLabel();
    if(subType == "EFID")
        effect->baseEffectId = GetData<formid>();
    else if(subType == "EFIT")
        effect->EffectData = GetData<Effect::baseEffect>();
    else if(ConditionsData(&effect->condition)) {}
    else return false;
    return true;
}
