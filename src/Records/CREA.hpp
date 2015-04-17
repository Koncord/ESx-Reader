/* 
 * File:   CREA.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 17 Апрель 2015 г., 14:19
 */

#ifndef CREA_HPP
#define	CREA_HPP

#include "../Record.hpp"
#include "../Subrecords/subACBS.hpp"
#include "../Subrecords/subSNAM.hpp"
#include "../Subrecords/subAIDT.hpp"
#include "../Types.hpp"

class RecordCREA : public Record
{
public:

    struct DATA
    {
        std::string edid;
        ObjectBounds objectBounds;
        std::string name;
        std::vector<formid> actorEffects;
        formid unarmedAttackEffect;
        uint16_t unarmedAttackAnimation;
        Configuration configuration;
        std::vector<Faction> factions;
        formid deathItem; // FormID of a LVLI record.
        formid voice; // FormID of a VTYP record.
        formid _template; // FormID of a CREA or LVLC record.
        Destruction destruction;
        formid script; // FormID of a SCPT record.
        Items items;
        AIData aiData;
        std::vector<formid> packages;
        std::vector<std::string> animations;
        uint8_t attackReach;
        formid combatStyle; // FormID of a CSTY record.
        formid bodyPartData; // FormID of a BPTD record.
        float turningSpeed;
        float baseScale;
        float footWeight;
        uint32_t impactMaterialType;
        uint32_t soundLevel;
        formid inheritsSoundsFrom; // FormID of a CREA record.
        formid impactDataset; // FormID of a IPDS record.
        formid MeleeWeaponList;
        struct SoundType
        {
            uint32_t type;
            std::vector<formid> sounds; // FormID of a SOUN record.
            std::vector<uint8_t> soundChances;
            enum class Type
            {
                LeftFoot = 0,
                RightFoot,
                LeftBackFoot,
                RightBackFoot,
                Idle,
                Aware,
                Attack,
                Hit,
                Death,
                Weapon,
                Movement,
                Conscious
            };
        };
        std::vector<SoundType> soundTypes;
#pragma pack(push, 1)
        struct _DATA
        {
            uint8_t type;
            uint8_t combatSkill;
            uint8_t magicSkill;
            uint8_t stealthSkill;
            uint16_t health;
            uint16_t unused;
            uint16_t damage;
            uint8_t strength;
            uint8_t perception;
            uint8_t endurance;
            uint8_t charisma;
            uint8_t intelligence;
            uint8_t agility;
            uint8_t luck;
            enum class Type
            {
                Animal,
                MutatedAnimal,
                MutatedInsect,
                Abomination,
                SuperMutant,
                FeralGhoul,
                Robot,
                Giant
            };
        } data;
#pragma pack(pop)
    } data;

    explicit RecordCREA(const RecHeader &head) : Record(head) { Parse(); }

    RecordCREA() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* CREA_HPP */

