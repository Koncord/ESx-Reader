/* 
 * File:   PACK.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 17 Апрель 2015 г., 16:05
 */

#ifndef PACK_HPP
#define	PACK_HPP

#include "../Record.hpp"
class RecordPACK : public Record
{
public:

    struct DATA
    {
        std::string edid;
        
        std::vector<CTDA> conditions;
        uint8_t idleAnimationFlags;
        uint32_t idleAnimationCount;
        float idleTimerSetting;
        std::vector<formid> animation; // FormID of a IDLE record, or null.
        formid combatStyle; // FormID of a CSTY record.
        
        uint32_t escortDistance;
        float followStartLocationTriggerRadius;
        uint16_t patrolFlags; // Repeatable = 0x01
        
        formid onBeginIdle; // FormID of an IDLE record, or null.
        Script onBeginEmbeddedScript;
        formid onBeginTopic; // FormID of a DIAL record, or null.
        
        formid onEndIdle; // FormID of an IDLE record, or null.
        Script onEndEmbeddedScript;
        formid onEndTopic; // FormID of a DIAL record, or null.
        
        formid onChangeIdle; // FormID of an IDLE record, or null.
        Script onChangeEmbeddedScript;
        formid onChangeTopic; // FormID of a DIAL record, or null.
        
        struct UseWaponData
        {
            uint32_t flags;
            uint8_t fireRate; // AutoFire = 0, VolleyFire = 1
            uint8_t fireCount; // NumberOfBursts = 0, RepeatFire = 1
            uint16_t NumberOfBursts;
            uint16_t ShotsPerVolleyMin;
            uint16_t ShotsPerVolleyMax;
            float PauseBetweenVolleyMin;
            float PauseBetweenVolleyMax;
            uint32_t unused;
            enum class Flag
            {
                AlwaysHit = 0x00000001,
                DoNoDamage = 0x00000100,
                CrouchToReload = 0x00010000,
                HoldFireWhenBlocked = 0x01000000
            };
        } useWeaponData;
        
        struct DialogData
        {
            float fov;
            formid topic;
            uint32_t flags;
            uint32_t unused;
            uint32_t dialogType; // Say Tosation = 0, Say To = 1
            enum class FlagValue
            {
                NoHeadtracking = 0x00000001,
                DontControlTargetMovement = 0x00000100
            };
            
        } dialogData;
        
        struct General
        {
            uint32_t flags;
            uint8_t type;
            int8_t byte;
            uint16_t falloutBehaviourFlag;
            uint16_t typeSpecificFlag;
            
            enum class Flag : unsigned
            {
                OffersServices = 0x00000001,
                MustReachLocation = 0x00000002,
                MustComplete = 0x00000004,
                LockDoorsAtPackageStart = 0x00000008,
                LockDoorsAtPackageEnd = 0x00000010,
                LockDoorsAtLocation = 0x00000020,
                UnockDoorsAtPackageStart = 0x00000040,
                UnockDoorsAtPackageEnd = 0x00000080,
                UnockDoorsAtLocation = 0x00000100,
                ContinueIfPCNear = 0x00000200,
                OncePerDay = 0x00000400,
                Unknown1 = 0x00000800,
                SkipFalloutBehavior = 0x00001000,
                AlwaysRun = 0x00002000,
                Unknown2 = 0x00004000,
                Unknown3 = 0x00008000,
                Unknown4 = 0x00010000,
                AlwaysSneak = 0x00020000,
                AllowSwimming = 0x00040000,
                AllowFalls = 0x00080000,
                HeadTrackingOff = 0x00100000,
                WeaponsUnequipped = 0x00200000,
                DefenceCombat = 0x00400000,
                WeaponDrawn = 0x00800000,
                NoIdleAnims = 0x01000000,
                PretendInCombat = 0x02000000,
                ContinueDuringCombat = 0x04000000,
                NoCombatAlert = 0x08000000,
                NoWarn = 0x10000000,
                AttackBehaviour = 0x10000000,
                Unknown5 = 0x20000000,
                Unknown6 = 0x40000000,
                Unknown7 = 0x80000000
            };
            
            enum class Type
            {
                Find  = 0,
                Follow,
                Escort,
                Eat,
                Sleep,
                Wander,
                Travel,
                Accompany,
                UseItemAt,
                Ambush,
                FleeNotCombat,
                Unknown1,
                Sandbox,
                Patrol,
                Guard,
                Dialogue,
                UseWeapon
            };
            
            enum class FalloutBehaviourFlag
            {
                HellosToPlayer = 0x0001,
                RandomConversations = 0x0002,
                ObserveCombatBehavior = 0x0004,
                Unknown1 = 0x0008,
                ReactionToPlayerActions = 0x0010,
                FriendlyFireComments = 0x0020,
                AggroRadiusBehavior = 0x0040,
                AllowIdleChatter = 0x0080,
                AvoidRadiation = 0x0100
            };
            
            enum class TypeFindFlag
            {
                AllowBuying = 0x0100,
                AllowKilling = 0x0200,
                AllowStealing = 0x0400
            };
            typedef TypeFindFlag TypeEscortFlag;
            typedef TypeFindFlag TypeEatFlag;
            enum class TypeWanderFlag
            {
                NoEating = 0x0001,
                NoSleeping = 0x0002,
                NoConversation = 0x0004,
                NoIdleMarkers = 0x0008,
                NoFurniture = 0x0010,
                NoWandering = 0x0020
            };
            typedef TypeFindFlag TypeSandboxFlag;
            enum class TypeUseItemAtFlag
            {
                SitDown = 0x0002,
                NoIdleMarkers = 0x0008,
                NoFurniture = 0x0010,
                NoWandering = 0x0020
            };
            enum class TypeAmbushFlag
            {
                HideWhileAmbushing = 0x0001
            };
            enum class TypeGuardFlag
            {
                RemainNearReferenceToGuard = 0x0004
            };
        } general;
        
        struct Location
        {
            uint32_t type;
            uint32_t location;
            int32_t radius;

            enum class TypeValuesAndLocationDataTypes
            {
                NearReference = 0, // FormID of a REFR, PGRE, PMIS, ACHR, ACRE or PLYR record.
                InCell, // FormID of a CELL record.
                NearCurrentLocation,
                NearEditorLocation,
                ObjectID, // FormID of a ACTI, DOOR, STAT, FURN, CREA, SPEL, NPC_, CONT, ARMO, AMMO, MISC, WEAP, BOOK, KEYM, ALCH or LIGH record.
                ObjectType, // ObjectTypes.hpp
                NearLinkedReference,
                AtPackageLocation
            };
        } location2; // ???
        struct LocationCol
        {
            Location location1, location2;
        };
        std::vector<LocationCol> locations;
        
        struct Schedule
        {
            int8_t month;
            int8_t dayOfWeek;
            uint8_t date;
            int8_t time;
            int32_t duration;
            
            enum class DayOfWeekValue
            {
                Any = -1,
                Sunday = 0,
                Monday,
                Tuesday,
                Wednesday,
                Thursday,
                Friday,
                Saturday,
                Weekdays,
                Weekends,
                MondayWednesdayFriday,
                TuesdayThursday
            };
        } schedule;
        struct Target
        {
            int32_t type;
            uint32_t target;
            int32_t countOrDistance;
            float unknown;
            enum TypeValueAndTargetDataType
            {
                SpecificReference = 0, // FormID of a REFR, PGRE, PMIS, ACHR, ACRE or PLYR record.
                ObjectID, // FormID of a ACTI, DOOR, STAT, FURN, CREA, SPEL, NPC_, LVLN, LVLC, CONT, ARMO, AMMO, MISC, WEAP, BOOK, KEYM, ALCH, LIGH, FACT or FLST record.
                ObjectType, // ObjectTypes.hpp
                LinkedReference
            };
        } target1, target2;
    } data;

    explicit RecordPACK(const RecHeader &head) : Record(head) { Parse(); }

    RecordPACK() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* PACK_HPP */

