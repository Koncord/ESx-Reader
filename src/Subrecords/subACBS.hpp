/* 
 * File:   subACBS.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 4 Февраль 2015 г., 19:01
 */

#ifndef SUBACBS_HPP
#define	SUBACBS_HPP

#pragma pack(push, 1)
struct Configuration
{
    uint32_t flags;
    uint16_t fatigue;
    uint16_t barterGold;
    union // If the 0x00000080 flag is set, the value is divided by 1000 to give a multiplier.
    {
        int16_t level;
        int16_t levelMult;
    };
    uint16_t calcMin;
    uint16_t calcMax;
    uint16_t speedMult;
    float karma; // Alignment
    int16_t dispositionBase;
    uint16_t templateFlags;
    
    enum class FLAG_CREA : uint32_t
    {
        Biped = 0x00000001,
        Essential = 0x00000002,
        WeaponAndShield = 0x00000004,
        Respawn = 0x00000008,
        Swims = 0x00000010,
        Flies = 0x00000020,
        Walks = 0x00000080,
        NoLowLevelProcessing = 0x00000200,
        NoBloodSpray = 0x00000800,
        NoBloodDecal = 0x00001000,
        NoHead = 0x00008000,
        NoRightArm = 0x00010000,
        NoLeftArm = 0x00020000,
        NoCombatInWater = 0x00040000,
        NoShadow = 0x00080000,
        NoVATSMelee = 0x00100000,
        AllowPCDialogue = 0x00200000,
        CantOpenDoors = 0x00400000,
        Immobile = 0x00800000,
        TiltFrontOrBack = 0x01000000,
        TiltLeftOrRight = 0x02000000,
        NoKnockdowns = 0x04000000,
        NotPushable = 0x08000000,
        AllowPickpocket = 0x10000000,
        IsGhost = 0x20000000,
        NoRotatingToHeadTrack = 0x40000000,
        Invulnerable = 0x80000000
    };
    enum class FLAG_NPC : uint32_t
    {
        Female = 0x00000001,
        Essential = 0x00000002,
        IsCharGenFacePreset = 0x00000004,
        Respawn = 0x00000008,
        AutocalcStats = 0x00000010,
        PCLevelMult = 0x00000080,
        UseTemplate = 0x00000100,
        NoLowLevelProcessing = 0x00000200,
        NoBloodSpray = 0x00000800,
        NoBloodDecal = 0x00001000,
        NoVATSMelee = 0x00100000,
        CanBeAllRaces = 0x00400000,
        NoKnockdowns = 0x04000000,
        NotPushable = 0x08000000,
        NoRotatingToHeadTrack = 0x40000000
    };
    enum TEMPLATEFLAGS
    {
        UseTraits = 0x0001,
        UseStats = 0x0002,
        UseFactions = 0x0004,
        UseActorEffectList = 0x0008,
        UseAIData = 0x0010,
        UseAIPackages = 0x0020,
        UseModelOrAnimation = 0x0040,
        UseBaseData = 0x0080,
        UseInventory = 0x0100,
        UseScript = 0x0200
    };
};
#pragma pack(pop)

#endif	/* SUBACBS_HPP */

