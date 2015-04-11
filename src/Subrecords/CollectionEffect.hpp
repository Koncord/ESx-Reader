/* 
 * File:   CollectionEffect.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 10 Апрель 2015 г., 20:52
 */

#ifndef COLLECTIONEFFECT_HPP
#define	COLLECTIONEFFECT_HPP

#include "../Types.hpp"
#include "../ActorValues.hpp"
#include "ConditionCollection.hpp"

struct Effect
{
    formid baseEffectId;
    struct baseEffect
    {
        uint32_t magnitude;
        uint32_t area;
        uint32_t duration;
        uint32_t type;
        int32_t value;
        enum Type
        {
            Self = 0,
            Touch,
            Target
        };
    } EffectData;
    CTDA condition;
};

#endif	/* COLLECTIONEFFECT_HPP */

