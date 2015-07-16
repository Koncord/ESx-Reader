/* 
 * File:   PGRE.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 2 Июль 2015 г., 13:12
 */

#ifndef PGRE_PMIS_HPP
#define	PGRE_PMIS_HPP

#include "../Record.hpp"

class RecordPGRE : public Record
{
public:

    struct DATA
    {
        std::string edid;
        formid baseId; // FormID of a NPC_ record.
        formid encounterZoneId; // ECZN record.
        float idleTime; // Patrol data.
        formid idleId; // Patrol data. FormID of an IDLE record, or null.
        Script script; // Patrol data.
        formid topicId; // Patrol data. FormID of a DIAL record, or null.
        int32_t levelModifier;
        formid ownerId; // Ownership data. FormID of a FACT, ACHR or NPC_ record.
        int32_t factionRank;
        int32_t count;
        float radius;
        float health;
        float scale;
        
        struct PositionRotation
        {
            float xPos, yPos, zPos;
            float xRot, yRot, zRot;
        } positionRotation;
        
        bool  parentActivateOnly;
        struct ActivateParentRef
        {
            formid referenceId; // FormID of a REFR, ACRE, ACHR, PGRE or PMIS record.
            float delay;
        };
        std::vector<ActivateParentRef> activateParentRefs;
        
        struct EnableParent
        {
            formid referenceId; // FormID of a PLYR, REFR, ACRE, ACHR, PGRE or PMIS record.
            uint8_t flags;
            uint8_t unused[3];
            enum Flags
            {
                SetEnableStateToOppositeOfParent = 0x01,
                PopIn = 0x02
            };
        } enableParent;
        
        formid linkedRefId; // REFR, ACRE, ACHR, PGRE or PMIS record.
        formid emittanceId; // LIGH or REGN record.
        formid multiBoundRefId; // REFR record.
        struct LinkedReferenceColor
        {
            rgba linkStartColor;
            rgba linkEndColor;
        } linkedReferenceColor[2];
        
    } data;

    explicit RecordPGRE(const RecHeader &head) : Record(head) { Parse(); }

    RecordPGRE() : Record() { Parse(); }
    virtual bool DoParse();
};
using RecordPMIS = RecordPGRE;

#endif	/* PGRE_PMIS_HPP */

