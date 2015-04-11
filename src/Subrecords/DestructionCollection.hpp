/* 
 * File:   DestructionCollection.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 10 Апрель 2015 г., 21:32
 */

#ifndef DESTRUCTIONCOLLECTION_HPP
#define	DESTRUCTIONCOLLECTION_HPP
#include "../Types.hpp"
#include "../debug_macros.hpp"

#pragma pack(push, 1)

struct Destruction
{
    todo(rename structures)
    struct DEST{
        uint32_t health;
        uint8_t count;
        bool targetable;
        uint8_t unknown[2];
    } dest;
    struct DSTAGE
    {
        struct DSTD
        {
            uint8_t healthPercent;
            uint8_t index;
            uint8_t damageStage;
            uint8_t flags;
            int32_t selfDPS; // Self Damage per Second
            uint32_t explosionId; // FormID of a EXPL record or null.
            uint32_t debrisId; // FormID of a DEBR record or null.
            int32_t debrisCount;
            enum FLAGS{
                isCapDamage = 0x01,
                isDisable = 0x02,
                isDestroy = 0x04
            };
        } dstd;
    };
    std::vector <DSTAGE> dstages;
};


#pragma pack(pop)

#endif	/* DESTRUCTIONCOLLECTION_HPP */

