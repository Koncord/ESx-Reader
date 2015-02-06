/* 
 * File:   subXNAM.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 5 Февраль 2015 г., 0:18
 */

#ifndef SUBXNAM_HPP
#define	SUBXNAM_HPP

#pragma pack(push, 1)
struct XNAM
{
    formid factionId;
    int32_t modifier;
    uint32_t groupCombatReaction;
    
    enum REACTION
    {
        Neutral = 0,
        Enemy,
        Ally,
        Friend
    };
};
#pragma pack(pop)

#endif	/* SUBXNAM_HPP */

