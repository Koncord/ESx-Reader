/* 
 * File:   subAIDT.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 4 Февраль 2015 г., 21:50
 */

#ifndef SUBAIDT_HPP
#define	SUBAIDT_HPP

#pragma pack(push, 1)
struct AIDT
{
    uint8_t aggression;
    uint8_t confidence;
    uint8_t energyLevel;
    uint8_t responsibility;
    uint8_t mood;
    uint8_t unused[3];
    uint32_t BuysOrSellsAndSerices;
    int8_t teaches;
    uint8_t maximumTraidingLevel;
    int8_t assistance;
    uint8_t aggroRadiusBehaviour;
    int32_t aggroRadius;
    
    enum AGGRESSION
    {
        Unaggressive = 0,
        Aggressive,
        VeryAggressive,
        Frenzied
    };
    enum CONFIDENCE
    {
        Cowardly = 0,
        Cautious,
        Average,
        Brave,
        Foolhardy
    };
    enum MOOD
    {
        Neutral = 0,
        Afraid,
        Annoyed,
        Cocky,
        Drugged,
        Pleasant,
        Angry,
        Sad
    };
    enum ASSISTANCE
    {
        HelpsNobody = 0,
        HelpsAllies,
        HelpsFriendsAndAllies
    };
    enum AGGRORADIUS
    {
        AggroRadiusBehavior = 0x01
    };
};
#pragma pack(pop)

#endif	/* SUBAIDT_HPP */

