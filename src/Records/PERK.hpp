/* 
 * File:   PERK.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 18:35
 */

#ifndef PERK_HPP
#define	PERK_HPP

#include "../Record.hpp"
#include <boost/variant/variant.hpp>

class RecordPERK: public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        std::string description;
        
        struct Effect
        {
            #pragma pack(push, 1)
            struct Header
            {
                uint8_t type;
                uint8_t rank;
                uint8_t priority;
                enum Type
                {
                    QuestAndStage = 0,
                    Ability = 1,
                    EntryPoint = 2
                };
            } header;
            #pragma pack(pop)

            struct QuestAndStageData
            {
                formid quest;
                int8_t stage;
                int8_t unused[3];
            };
            
            struct EntryPoint
            {
                uint8_t entryPoint;
                uint8_t function;
                uint8_t perkConditionTabCount;
                enum EntryPointFlag
                {
                    CalculateWeaponDamage = 0,
                    CalculateMyCriticalHitChance,
                    CalculateMyCriticalHitDamage,
                    CalculateWeaponAttackAPCost,
                    CalculateMineExplodeChance,
                    AdjustRangePenalty,
                    AdjustLimbDamage,
                    CalculateWeaponRange,
                    CalculateToHitChance,
                    AdjustExperiencePoints,
                    AdjustGainedSkillPoints,
                    AdjustBookSkillPoints,
                    ModifyRecoveredHealth,
                    CalculateInventoryAPCost,
                    GetDisposition,
                    GetShouldAttack,
                    GetShouldAssist,
                    CalculateBuyPrice,
                    GetBadKarma,
                    GetGoodKarma,
                    IgnoreLockedTerminal,
                    AddLeveledListOnDeath,
                    GetMaxCarryWeight,
                    ModifyAddictionChance,
                    ModifyAddictionDuration,
                    ModifyPositiveChemDuration,
                    AdjustDrinkingRadiation,
                    Activate,
                    MysteriousStranger,
                    HasParalyzingPalm,
                    HackingScienceBonus,
                    IgnoreRunningDuringDetection,
                    IgnoreBrokenLock,
                    HasConcentratedFire,
                    CalculateGunSpread,
                    PlayerKillAPReward,
                    ModifyEnemyCriticalHitChance
                };
            };
            boost::variant<QuestAndStageData, formid, EntryPoint> data;
            
            struct PerkCondtitionCollection
            {
                int8_t runOn;
                std::vector<CTDA> conditions;
            } condtitionColl;
            
            uint8_t entryPointFunctionType;
            struct EPFD_2
            {
                float val0, val1;
            };
            struct EPFD_5
            {
                uint32_t actorValue;
                float value;
            };
            boost::variant<std::vector<uint8_t>, float, EPFD_2, formid, EPFD_5> entryPointFunctionData;
            std::string buttonLabel;
            uint16_t scriptFlags;
            enum ScriptFlag
            {
                RunImmediately = 0x0001
            };
            SCRIPT script;
        };
        std::vector<Effect> effects;
        
        #pragma pack(push, 1)
        CTDA conditions;
        struct _DATA
        {
          uint8_t trait; // bool
          int8_t minLevel;
          int8_t ranks;
          uint8_t playable; // bool
          uint8_t hidden;  // bool
        } data;
        #pragma pack(pop)
    } data;

    explicit RecordPERK(const RecHeader &head) : Record(head) { Parse(); }

    RecordPERK() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* PERK_HPP */

