/* 
 * File:   CSTY.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 16 Апрель 2015 г., 22:05
 */

#ifndef CSTY_HPP
#define	CSTY_HPP

#include "../Record.hpp"
class RecordCSTY : public Record
{
public:

    struct DATA
    {
        std::string edid;
        
        #pragma pack(push, 1)
        struct Advanced_Standard
        {
            uint8_t maneuverDecision_DodgeChance; // in Percent
            uint8_t maneuverDecision_LeftOrRightChance; // in percent
            uint8_t unused0[2];
            
            float maneuverDecision_DodgeRightOrLeftTimerMin;
            float maneuverDecision_DodgeRightOrLeftTimerMax;
            float maneuverDecision_DodgeForwardTimerMin;
            float maneuverDecision_DodgeForwardTimerMax;
            float maneuverDecision_DodgeBackTimerMin;
            float maneuverDecision_DodgeBackTimerMax;
            float maneuverDecision_DodgeIdleTimerMin;
            float maneuverDecision_DodgeIdleTimerMax;
            
            uint8_t meleeDecision_BlockChance; // in percent
            uint8_t meleeDecision_AttackChance; // in percent;
            uint8_t unused1[2];
            
            float meleeDecision_RecoilOrStaggerBonusToAttack;
            float meleeDecision_UnconsciousBonusToAttack;
            float meleeDecision_HandToHandBonusToAttack;
            
           uint8_t meleeDecision_PowerAttacks_PowerAttackChance;
           uint8_t unused2[3];
           float meleeDecision_PowerAttacks_RecoilOrStaggerBonusToPower;
           float meleeDecision_PowerAttacks_UnconsciousBonusToPowerAttack;
           uint8_t meleeDecision_PowerAttacks_Normal;
           uint8_t meleeDecision_PowerAttacks_Forward;
           uint8_t meleeDecision_PowerAttacks_Back;
           uint8_t meleeDecision_PowerAttacks_Left;
           uint8_t meleeDecision_PowerAttacks_Right;
           uint8_t unused3[3];
           
           float meleeDecision_HoldTimerMin;
           float meleeDecision_HoldTimerMax;
           
           uint16_t flags;
           uint8_t unused4[2];
           uint8_t maneuverDecision_AcrobaticDodgeAndChance;
           uint8_t MeleeDecision_PowerAttacks_RushingAttackChance; // in percent
           uint8_t unused5[2];
           float meleeDecision_PowerAttacks_RushingAttackDistanceMult;
           
           enum Flag
           {
                ChooseAttackUsingPercentChance = 0x0001,
                MeleeAlertOK =0x0002,
                FleeBasedOnPersonalSurvival = 0x0004,
                Unknown = 0x0008,
                IgnoreThreats = 0x0010,
                IgnoreDamagingSelf = 0x0020,
                IgnoreDamagingGroup = 0x0040,
                IgnoreDamagingSpectators = 0x0080,
                CannotUseStealthboy = 0x0100
           };
        } advanced_Standard;
        struct Advanced_Advanced
        {
           float dodgeFatigueModMult;
           float dodgeFatigueModBase;
           float encumbSpeedModBase; TODO("check order of variables: encumbSpeedModBase and encumbSpeedModMult")
           float encumbSpeedModMult;
           float dodgeWhileUnderAttackMult;
           float dodgeNotUnderAttackMult;
           float dodgeBackWhileUnderAttackMult;
           float dodgeBackNotUnderAttackMult;
           float dodgeForwardWhileUnderAttackMult;
           float dodgeForwardNotUnderAttackMult;
           
           float blockSkillModifierMult;
           float blockSkillModifierBase;
           float blockWhileUnderAttackMult;
           float blockNotUnderAttackMult;
           
           float attackSkillModifierMult;
           float attackSkillModifierBase;
           float attackWhileUnderAttackMult;
           float attackNotUnderAttackMult;
           float attackDuringBlockMult;
           
           float PowerAttackFatigueModBase;
           float PowerAttackFatigueModMult;
        } advanced_Advanced;
        
        struct Simple
        {
            float coverSearchRadius;
            float takeCoverChance;
            float waitTimerMin;
            float waitTimerMax;
            float waitToFireTimerMin;
            float waitToFireTimerMax;
            float fireTimerMin;
            float fireTimerMax;
            
            float rangedWeaponRageMultMin;
            uint8_t unused[4];
            uint32_t weaponRestrictions;
            float rangedWeaponRageMultMax;
            
            float maxTargetingFOV;
            float combatRadius;
            float semiAutoFiringDelayMultMin;
            float semiAutoFiringDelayMultMax;
            enum WeaponRestrictions
            {
                None = 0,
                MeleeOnly,
                RangedOnly
            };
            
        } simple;
    #pragma pack(pop)
        
    } data;

    explicit RecordCSTY(const RecHeader &head) : Record(head) { Parse(); }

    RecordCSTY() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* CSTY_HPP */

