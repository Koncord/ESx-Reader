/* 
 * File:   WEAP.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 30 Январь 2015 г., 21:16
 */

#ifndef WEAP_HPP
#define	WEAP_HPP

#include "../Record.hpp"
#include "../Subrecords/subETYP.hpp"

class RecordWEAP : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        Destruction destruction;
        
        formid scriptId;
        formid objectEffectId;
        formid ammoId;
        uint32_t repairLstId;
        ETYP etyp; // equipType
        std::string embeddedWeaponNode;
        ObjectBounds objectBounds;
        uint32_t soundLevel;
#pragma pack(push, 1)
        struct _DATA
        {
            int32_t value;
            int32_t health;
            float weight;
            int16_t baseDamage;
            uint8_t ClipSize;
        } data;
        
        struct DNAM
        {
            uint32_t animType;
            float ainmMult;
            float Reach;
            uint8_t flags1;
            uint8_t gripAnim;
            uint8_t animUse;
            uint8_t reloadAnim;
            float minSpread;
            float spread;
            uint8_t unknown[4];
            float sightFOV;
            uint8_t unused[4];
            uint32_t projectileId; // FormID of a PROJ record, or null.
            uint8_t baseVATSChance;
            uint8_t attackAnim;
            uint8_t projectileCount;
            uint8_t embeddedWeapActorValue;
            float minRange;
            float maxRange;
            uint32_t onHit;
            uint32_t flags2;
            float animAttackMult;
            float fireRate;
            float overrideActorPoints;
            
            float rumbleLMS;
            float rumbleRMS;
            float rumbleDuration;
            
            float overrideDamageToWeapMult;
            float attackShotsPerSec;
            float reloadTime;
            float jamTime;
            float aimArc;
            int skill;
            
            uint32_t rumblePattern;
            float rumbleWavelength;
            
            float limbDamageMult;
            int32_t resistanceType;
            float sightUsage;
            
            float semiAuthomaticFireDelayMin;
            float semiAuthomaticFireDelayMax;
        } dnam;
        
        struct CRDT
        {
            uint16_t critDmg;
            uint8_t unused[2];
            float critPercentMult;
            bool onDeath;
            uint8_t unused2[3];
            uint32_t effectId; // FormID of a SPEL record, or null.
        } crdt;
#pragma pack(pop)
        
        enum FLAGS1
        {
            IgnoresNormalWeaponResistance = 0x01,
            IsAuthomatic = 0x02,
            HasScope = 0x04,
            CantDrop = 0x08,
            HideBackpack = 0x10,
            EmbeddedWeapon = 0x20,
            DontUse1stPresonISAnimation = 0x40,
            NonPlayable = 0x80
        };
        enum FLAGS2
        {
           PlayerOnly = 0x00000001,
           NPCsUseAmmo = 0x00000002,
           NoJamAfterReload = 0x00000008,
           OverrideActionPoints = 0x00000010,
           MinorCrime  = 0x00000020,
           RangeFixed  = 0x00000040,
           NotUsedInNormalCombat  = 0x00000040,
           OverrideDamageToWeaponMult  = 0x00000080,
           DontUse3rdPresonISAnimation  = 0x00000100,
           ShortBurst  = 0x00000200,
           RumbleAlternate  = 0x00000400,
           LongBurst = 0x00000800 
        };
        enum SNDLVL
        {
            Loud = 0,
            Normal,
            Silent
        };
        enum ONHITVALUES
        {
            NormalFormulaBehaviour = 0,
            DismemberOnly,
            ExplodeOnly,
            NoDismemberOrExplode
        };
    } data;

    explicit RecordWEAP(const RecHeader &head) : Record(head){Parse(); }
    RecordWEAP() : Record() {Parse();}
    virtual bool DoParse();
};
 

#endif	/* WEAP_HPP */
