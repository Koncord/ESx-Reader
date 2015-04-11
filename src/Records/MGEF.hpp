/* 
 * File:   MGEF.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 10 Апрель 2015 г., 21:59
 */

#ifndef MGEF_HPP
#define	MGEF_HPP

#include "../Record.hpp"

class RecordMGEF : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        std::string description;
        #pragma pack(push, 1)
        struct _DATA
        {
            uint32_t flags;
            float baseCost; // unused
            formid associatedItem;
            int32_t magicSchool; // unused
            int32_t resistanceType;
            uint32_t unknown;
            formid light;
            float projectileSpeed;
            formid effectShader;
            formid objectDisplayShader;
            formid effectSound;
            formid boldSound;
            formid hitSound;
            formid areaSound;
            float constantEffectEnchantmentFactor; // unused
            float constantEffectBarterFactor; // unused
            uint32_t archtype;
            int32_t actorValue;
            
            enum class Flag
            {
                Hostile = 0x00000001,
                Recover = 0x00000002,
                Detrimental = 0x00000004,
                Unknown0 = 0x00000008,
                Self = 0x00000010,
                Touch = 0x00000020,
                Target = 0x00000040,
                NoDuration = 0x00000080,
                NoMagnitude = 0x00000100,
                NoArea = 0x00000200,
                FXPersist = 0x00000400,
                Unknown1 = 0x00000800,
                GoryVisuals = 0x00001000,
                DisplayNameOnly = 0x00002000,
                Unknown2 = 0x00004000,
                RadioBroadcast = 0x00008000,
                Unknown3 = 0x00010000,
                Unknown4 = 0x00020000,
                Unknown5 = 0x00040000,
                Useskill = 0x00080000,
                Useattribute = 0x00100000,
                Unknown6 = 0x00200000,
                Unknown7 = 0x00400000,
                Unknown8 = 0x00800000,
                Painless = 0x01000000,
                SprayProjectileType = 0x02000000,
                BoltProjectileType = 0x04000000,
                NoHitEffect = 0x08000000,
                NoDeathDispel = 0x10000000,
                Unknown9 = 0x20000000
            };
            enum class Archtype
            {
                ValueModifier =0,
                Script,
                Dispel,
                CureDisease,
                Unknown0,
                Unknown1,
                Unknown2,
                Unknown3,
                Unknown4,
                Unknown5,
                Unknown6,
                Invisibility,
                Chameleon,
                Light,
                Unknown7,
                Unknown8,
                Lock,
                Open,
                BoundItem,
                SummonCreature,
                Unknown9,
                Unknown10,
                Unknown11,
                Unknown12,
                Paralysis,
                Unknown13,
                Unknown14,
                Unknown15,
                Unknown16,
                Unknown17,
                CureParalysis,
                CureAddiction,
                CurePoison,
                Concussion,
                ValueAndParts
            };
        }data;
        #pragma pack(pop)
    } data;

    explicit RecordMGEF(const RecHeader &head) : Record(head) { Parse(); }

    RecordMGEF() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* MGEF_HPP */

