#ifndef RECORD_HPP
#define RECORD_HPP
#include <cstdint>
#include <memory>
#include <vector>
#include "Group.hpp"
#include "SubRecord.hpp"

typedef uint32_t formid;

typedef enum
{
    isMaster = 0x00000001,
    isDeleted = 0x00000020,
    isBorderRegion = 0x00000040,
    isConstant = 0x00000040,
    isHiddenFromLocalMap = 0x00000040,
    isTurnOffFire = 0x00000080,
    isInaccessible = 0x00000100,
    isOnLocalMap = 0x00000200,
    isQuestItem = 0x00000400,
    isInitiallyDisabled = 0x00000800,
    isIgnored = 0x00001000,
    isNoVoiceFilter = 0x00002000,
    isVisibleWhenDistant = 0x00008000,
    isRandomAnimStart = 0x00010000,
    isDangerous = 0x00020000,
    isOffLimits = 0x00020000,
    isInteriorCell = 0x00020000,
    isCompressed = 0x00040000,
    isCantWait = 0x00080000,
    isObstacle = 0x02000000,
    isNoAIAcquire = 0x02000000,
    isNavMeshGenerationFilter = 0x04000000,
    isNavMeshGenerationBoundingBox = 0x08000000,
    isNonPipboy = 0x10000000,
    isChildCanUse = 0x20000000,
    isNavMeshGenerationGround = 0x40000000
} Flag;

struct RecHeader
{
    char type[4];
    uint32_t dataSize;
    uint32_t flags;
    formid id;
    uint32_t revision;
    uint16_t version;
};

#pragma pack(push, 1)
struct DESTRUCTION
{
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

struct CTDA
{
    uint8_t type;
    uint8_t unused[3];
    union { //  	If not a valid GLOB record FormID, is interpreted as a float32.
        formid globalId;
        float floatValue;
    }comparisonValue;
    uint32_t functionIndex;
    uint8_t parameter1[4];
    uint8_t parameter2[4];
    uint32_t runOn; // Values and what they correspond to are given below.
    formid referenceId; //  PLYR, ACHR, ACRE, REFR, PMIS or PGRE reference on which to apply the function, or null.
    enum TypeValues
    {
        CombineConditionsUsingOR = 0x0001, // default is to use AND
        RunOnTarget = 0x0002,
        UseGlobal = 0x0004,
        EqualTo = 0x0000,
        NotEqualTo = 0x2000,
        GreaterThan = 0x4000,
        GreaterThanOrEqualTo = 0x6000,
        LessThan = 0x8000,
        LessThanOrEqualTo = 0xA000
    };
    enum FunctionIndices
    {
	GetDistance = 1,
	GetLocked = 5,
	GetPos = 6,
	GetAngle = 8,
	GetStartingPos = 10,
	GetStartingAngle = 11,
	GetSecondsPassed = 12,
	GetActorValue = 14,
	GetCurrentTime = 18,
	GetScale = 24,
	IsMoving = 25,
	IsTurning = 26,
	GetLineOfSight = 27,
	GetInSameCell = 32,
	GetDisabled = 35,
	MenuMode = 36,
	GetDisease = 39,
	GetVampire = 40,
	GetClothingValue = 41,
	SameFaction = 42,
	SameRace = 43,
	SameSex = 44,
	GetDetected = 45,
	GetDead = 46,
	GetItemCount = 47,
	GetGold = 48,
	GetSleeping = 49,
	GetTalkedToPC = 50,
	GetScriptVariable = 53,
	GetQuestRunning = 56,
	GetStage = 58,
	GetStageDone = 59,
	GetFactionRankDifference = 60,
	GetAlarmed = 61,
	IsRaining = 62,
	GetAttacked = 63,
	GetIsCreature = 64,
	GetLockLevel = 65,
	GetShouldAttack = 66,
	GetInCell = 67,
	GetIsClass = 68,
	GetIsRace = 69,
	GetIsSex = 70,
	GetInFaction = 71,
	GetIsID = 72,
	GetFactionRank = 73,
	GetGlobalValue = 74,
	IsSnowing = 75,
	GetDisposition = 76,
	GetRandomPercent = 77,
	GetQuestVariable = 79,
	GetLevel = 80,
	GetArmorRating = 81,
	GetDeadCount = 84,
	GetIsAlerted = 91,
	GetHeadingAngle = 99,
	IsWeaponOut = 101,
	IsTorchOut = 102,
	IsShieldOut = 103,
	IsFacingUp = 106,
	GetKnockedState = 107,
	GetWeaponAnimType = 108,
	IsWeaponSkillType = 109,
	GetCurrentAIPackage = 110,
	IsWaiting = 111,
	IsIdlePlaying = 112,
	GetMinorCrimeCount = 116,
	GetMajorCrimeCount = 117,
	GetActorAggroRadiusViolated = 118,
	GetCrime = 122,
	IsGreetingPlayer = 123,
	IsGuard = 125,
	HasBeenEaten = 127,
	GetFatiguePercentage = 128,
	GetPCIsClass = 129,
	GetPCIsRace = 130,
	GetPCIsSex = 131,
	GetPCInFaction = 132,
	SameFactionAsPC = 133,
	SameRaceAsPC = 134,
	SameSexAsPC = 135,
	GetIsReference = 136,
	IsTalking = 141,
	GetWalkSpeed = 142,
	GetCurrentAIProcedure = 143,
	GetTrespassWarningLevel = 144,
	IsTrespassing = 145,
	IsInMyOwnedCell = 146,
	GetWindSpeed = 147,
	GetCurrentWeatherPercent = 148,
	GetIsCurrentWeather = 149,
	IsContinuingPackagePCNear = 150,
	CanHaveFlames = 153,
	HasFlames = 154,
	GetOpenState = 157,
	GetSitting = 159,
	GetFurnitureMarkerID = 160,
	GetIsCurrentPackage = 161,
	IsCurrentFurnitureRef = 162,
	IsCurrentFurnitureObj = 163,
	GetDayOfWeek = 170,
	GetTalkedToPCParam = 172,
	IsPCSleeping = 175,
	IsPCAMurderer = 176,
	GetDetectionLevel = 180,
	GetEquipped = 182,
	IsSwimming = 185,
	GetAmountSoldStolen = 190,
	GetIgnoreCrime = 192,
	GetPCExpelled = 193,
	GetPCFactionMurder = 195,
	GetPCEnemyofFaction = 197,
	GetPCFactionAttack = 199,
	GetDestroyed = 203,
	HasMagicEffect = 214,
	GetDefaultOpen = 215,
	GetAnimAction = 219,
	IsSpellTarget = 223,
	GetVATSMode = 224,
	GetPersuasionNumber = 225,
	GetSandman = 226,
	GetCannibal = 227,
	GetIsClassDefault = 228,
	GetClassDefaultMatch = 229,
	GetInCellParam = 230,
	GetVatsTargetHeight = 235,
	GetIsGhost = 237,
	GetUnconscious = 242,
	GetRestrained = 244,
	GetIsUsedItem = 246,
	GetIsUsedItemType = 247,
	GetIsPlayableRace = 254,
	GetOffersServicesNow = 255,
	GetUsedItemLevel = 258,
	GetUsedItemActivate = 259,
	GetBarterGold = 264,
	IsTimePassing = 265,
	IsPleasant = 266,
	IsCloudy = 277,
	GetArmorRatingUpperBody = 274,
	GetBaseActorValue = 277,
	IsOwner = 278,
	IsCellOwner = 280,
	IsHorseStolen = 282,
	IsLeftUp = 285,
	IsSneaking = 286,
	IsRunning = 287,
	GetFriendHit = 288,
	IsInCombat = 289,
	IsInInterior = 300,
	IsWaterObject = 304,
	IsActorUsingATorch = 306,
	IsXBox = 309,
	GetInWorldspace = 310,
	GetPCMiscStat = 312,
	IsActorEvil = 313,
	IsActorAVictim = 314,
	GetTotalPersuasionNumber = 315,
	GetIdleDoneOnce = 318,
	GetNoRumors = 320,
	WhichServiceMenu = 323,
	IsRidingHorse = 327,
	IsInDangerousWater = 332,
	GetIgnoreFriendlyHits = 338,
	IsPlayersLastRiddenHorse = 339,
	IsActor = 353,
	IsEssential = 354,
	IsPlayerMovingIntoNewSpace = 358,
	GetTimeDead = 361,
	GetPlayerHasLastRiddenHorse = 362,
	IsChild = 365,
	GetLastPlayerAction = 367,
	IsPlayerActionActive = 368,
	IsTalkingActivatorActor = 370,
	IsInList = 372,
	GetHasNote = 282,
	GetHitLocation = 391,
	IsPC1stPerson = 392,
	GetCauseofDeath = 397,
	IsLimbGone = 398,
	IsWeaponInList = 399,
	HasFriendDisposition = 403,
	GetVATSValue = 408,
	IsKiller = 409,
	IsKillerObject = 410,
	GetFactionCombatReaction = 411,
	Exists = 415,
	GetGroupMemberCount = 416,
	GetGroupTargetCount = 417,
	GetIsVoiceType = 427,
	GetPlantedExplosive = 428,
	IsActorTalkingThroughActivator = 430,
	GetHealthPercentage = 431,
	GetIsObjectType = 433,
	GetDialogueEmotion = 435,
	GetDialogueEmotionValue = 436,
	GetIsCreatureType = 438,
	GetInZone = 446,
	HasPerk = 449,
	GetFactionRelation = 450,
	IsLastIdlePlayed = 451,
	GetPlayerTeammate = 454,
	GetPlayerTeammateCount = 455,
	GetActorCrimePlayerEnemy = 459,
	GetActorFactionPlayerEnemy = 460,
	IsPlayerGrabbedRef = 464,
	GetDestructionStage = 471,
	GetIsAlignment = 474,
	GetThreatRatio = 478,
	GetIsUsedItemEquipType = 480,
	GetConcussed = 489,
	GetMapMarkerVisible = 492,
	GetPermanentActorValue = 495,
	GetKillingBlowLimb = 496,
	GetWeaponHealthPerc = 500,
	GetRadiationLevel = 503,
	GetLastHitCritical = 510,
	IsCombatTarget = 515,
	GetVATSRightAreaFree = 518,
	GetVATSLeftAreaFree = 519,
	GetVATSBackAreaFree = 520,
	GetVATSFrontAreaFree = 521,
	GetIsLockBroken = 522,
	IsPS3 = 523,
	IsWin32 = 524,
	GetVATSRightTargetVisible = 525,
	GetVATSLeftTargetVisible = 526,
	GetVATSBackTargetVisible = 527,
	GetVATSFrontTargetVisible = 528,
	IsInCriticalStage = 531,
	GetXPForNextLevel = 533,
	GetQuestCompleted = 546,
	IsGoreDisabled = 550,
	GetSpellUsageNum = 555,
	GetActorsInHigh = 557,
	HasLoaded3D = 558
    };
};
#pragma pack(pop)

#pragma pack(push, 1)
struct ITEM
{
    struct CNTO
    {
        formid itemId; // ARMO, AMMO, MISC, WEAP, BOOK, LVLI, KEYM, ALCH, NOTE, MSTT or STAT record.
        int32_t count;
    }item;
    struct COED
    {
        uint32_t ownerId;
        uint32_t special; // FormID of a GLOB record, an integer representing the required rank, or null.
        float condition;
    }extra;
};
typedef std::vector<ITEM> ITEMCOL;

struct SCRIPT
{
    std::vector<uint8_t> compiled;
    std::string source;
    std::vector<formid> globRefs; // ACTI, DOOR, STAT, FURN, CREA, SPEL, NPC_, CONT, ARMO,
                                   // AMMO, MISC, WEAP, IMAD, BOOK, KEYM, ALCH, LIGH, QUST, PLYR,
                                   // PACK, LVLI, ECZN, EXPL, FLST, IDLM, PMIS, FACT, ACHR, REFR, ACRE,
                                   // GLOB, DIAL, CELL, SOUN, MGEF, WTHR, CLAS, EFSH, RACE, LVLC, CSTY,
                                   // WRLD, SCPT, IMGS, MESG, MSTT, MUSC, NOTE, PERK, PGRE, PROJ, LVLN,
                                   // WATR, ENCH, TREE, TERM, HAIR, EYES, ADDN or NULL record.
    std::vector<uint32_t> locRefs;
    struct LOCALVAR
    {
        struct SLSD
        {
            uint32_t index;
            uint8_t unused[12];
            bool isLongOrShort;
            uint8_t unused1[7];
        }data;

        std::string name;
    };
    std::vector<LOCALVAR> localVariables;
    struct SCHR
    {
        uint8_t unused[4];
        uint32_t refCount;
        uint32_t compiledSize;
        uint32_t variableCount;
        uint16_t type;
        bool enabled;
        uint8_t unused1;
    } main;
    enum TYPE
    {
        Object = 0,
        Quest,
        Effect = 0x100
    };
};
typedef std::vector<SCRIPT> SCRIPTCOL;

struct EFFECT
{
    formid baseEffectId;
    struct EFIT
    {
        uint32_t magnitude;
        uint32_t area;
        uint32_t duration;
        uint32_t type;
        int32_t value;
        enum TYPE
        {
            Self = 0,
            Touch,
            Target
        };
        enum ACTORVALUE
        {
            None=-1,
            Aggression=0,
            Confidence,
            Energy,
            Responsibility,
            Mood,
            Strength,
            Perception,
            Endurance,
            Charisma,
            Intelligence,
            Agility,
            Luck,
            ActionPoints,
            CarryWeight,
            CriticalChance,
            HealRate,
            Health,
            MeleeDamage,
            DamageResistance,
            PoisonResistance,
            RadResistance,
            SpeedMultiplier,
            Fatigue,
            Karma,
            XP,
            PerceptionCondition,
            EnduranceCondition,
            LeftAttackCondition,
            RightAttackCondition,
            LeftMobilityCondition,
            RightMobilityCondition,
            BrainCondition,
            Barter,
            BigGuns,
            EnergyWeapons,
            Explosives,
            Lockpick,
            Medicine,
            MeleeWeapons,
            Repair,
            Science,
            SmallGuns,
            Sneak,
            Speech,
            Throwing, // unused
            Unarmed,
            InventoryWeight,
            Paralysis,
            Invisibility,
            Chameleon,
            NightEye,
            DetectLifeRange,
            FireResistance,
            WaterBreathing,
            RadLevel,
            BloodyMess,
            UnarmedDamage,
            Assistance,
            ElectricResistance,
            FrostResistance,
            EnergyResistance,
            EMPResistance,
            unknown1,
            unknown2,
            unknown3,
            unknown4,
            unknown5,
            unknown6,
            unknown7,
            unknown8,
            unknown9,
            unknown10,
            IgnoreNegativeEffects
        };
    } EffectData;
    CTDA condition;
};

#pragma pack(pop)

class Record
{

public:
    RecHeader head;

protected:
    SubRecHeader subhead;
    
    struct RAWDATA
    {
        std::unique_ptr<uint8_t[]> data;
        uint32_t pos;
        uint32_t size;
    } rawdata;

    template<class T>
    T GetData()
    {
        T tmp = *(reinterpret_cast<T*> (&rawdata.data.get()[rawdata.pos]));
        rawdata.pos += sizeof (T);
        return tmp;
    }
    
    template<class T>
    T GetData(uint32_t size)
    {
        T tmp = *(reinterpret_cast<T*> (&rawdata.data.get()[rawdata.pos]));
        rawdata.pos += size;
        return tmp;
    }
    
    std::string GetString()
    {
        std::string str((char*) &rawdata.data.get()[rawdata.pos], subhead.dataSize-1);
        rawdata.pos += subhead.dataSize;
        return str;
    }
    
    const std::string GetLabel() {return std::string(subhead.type, 4);}
    void ParseHead(const RecHeader &head);
    void ReadSubHeader();
    void IgnoreBytes(uint32_t value) { rawdata.pos += value; }
    void IgnoreSubRecord() { IgnoreBytes(subhead.dataSize); }
    
    // --------------------- SubRecord collections -----------------------------
    bool SkipModelData();
    bool DestructionData(DESTRUCTION *destruction);
    bool ConditionsData(CTDA *cond);
    bool SubItemCollection(ITEMCOL *items);
    bool ScriptCollection(SCRIPT *scr);
    bool EffectCollection(EFFECT * effect);
    // -------------------------------------------------------------------------
protected:
    virtual bool DoParse() = 0;
    explicit Record(const RecHeader &head);
    Record();
    virtual ~Record();

public:

    bool GetFlag(Flag flag) { return head.flags & flag; }
    static RecHeader ReadHeader();
    void Parse();
};

#endif // RECORD_HPP
