/* 
 * File:   REFR.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 5 Февраль 2015 г., 16:51
 */

#ifndef REFR_HPP
#define	REFR_HPP

#include "../Types.hpp"
#include "../Record.hpp"

class RecordREFR: public Record // Last XNDP
{
public:

    struct DATA
    {
        std::string edid;
        formid baseId;
        formid encounterZoneId; // ECZN record.
        formid targetId; // REFR, ACRE, ACHR, PGRE or PMIS record.
        formid idleId; // IDLE record, or null.
        formid topicId; // DIAL record, or null.
        formid ownerId; // Ownership data. FormID of a FACT, ACHR or NPC_ record.
        formid ammoTypeId; // AMMO record, or null.
        formid litWaterId; // REFR record.
        formid linkedRefId; // REFR, ACRE, ACHR, PGRE or PMIS record.
        formid emittanceId; // LIGH or REGN record.
        formid multiBoundRefId; // REFR record.
        // XRGD
        // XRGB
        int32_t levelModifier;
        float idleTime;
        uint32_t CollisionLayer;
        uint8_t mapMarkerFlags;
        int32_t factionRank;
        int32_t count;
        float radius;
        float health;
        float radiation;
        float charge;
        int32_t ammoCount;
        std::string mapMarkerName;
        uint8_t flags; // Activate parents.
        uint32_t actionFlag;
        
        Script script;
        // XPWR
        struct XNDP
        {
            formid navMeshId; // NAVM record.
            uint8_t unknown[4];
        } navigationDoorLink;
        struct XESP
        {
            formid refId;
            uint8_t flags;
            uint8_t unknown[3];
            enum FLAG
            {
                SetEnableStateToOppositeOfParent = 0x01,
                PopIn = 0x02
            };
        } enableParent;
        struct XAPR
        {
            formid refId; // REFR, ACRE, ACHR, PGRE or PMIS record.
            float delay;
        };
        std::vector<XAPR> activateParentRefs; // Activate parents
        struct XLOC
        {
            uint8_t level;
            uint8_t unused[3];
            formid key;
            uint8_t flags;
            uint8_t unknown[11];
            enum FLAGS
            {
                UseDefault =    0x00000001,
                Activatee =     0x00000002,
                Open =          0x00000004,
                OpenByDefault = 0x00000008
            };
        } lockData;
        struct XRDO
        {
            float rangeRadius;
            uint32_t broadcastRangeType;
            float staticPercentage;
            formid positionRefId; // REFR, ACRE, ACHR, PGRE or PMIS record, or null.
            enum RANGETYPE
            {
                Radius = 0,
                Everywhere,
                WorldspaceAndLinkedInteriors,
                LinkedInteriors,
                CurrentCellOnly
            };
        } radioData;
        struct TNAM
        {
            uint8_t type;
            uint8_t unused;
            enum TYPE
            {
                None = 0,
                City,
                Settlement,
                Encampment,
                NaturalLandmark,
                Cave,
                Factory,
                Monument,
                Military,
                Office,
                TownRuins,
                UrbanRuins,
                SewerRuins,
                Metro,
                Vault
            };
        } mapMarkerData;
        struct XTEL
        {
            formid door; // REFR record.
            float xPos;
            float yPos;
            float zPos;
            float xRot;
            float yRot;
            float zRot;
            uint32_t flags;
            enum FLAGS
            {
                NoAlarm = 0x00000001
            };
        } teleportDestination;
        struct XMBO
        {
            float x;
            float y;
            float z;
        } boundHalfExtents;
        struct XPRM
        {
            float xBound;
            float yBound;
            float zBound;
            float red;
            float green;
            float blue;
            uint8_t unknown;
            uint32_t type;
            
            enum TYPE
            {
                None = 0,
                Box,
                Sphere,
                PortalBox
            };
        } primitive;
        struct RCLR
        {
            rgba linkStartColor;
            rgba linkEndColor;
        };
        struct XCLP
        {
            rgba linkStartColor;
            rgba linkEndColor;
        };
    } data;

    explicit RecordREFR(const RecHeader &head) : Record(head) { Parse(); }

    RecordREFR() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* REFR_HPP */

