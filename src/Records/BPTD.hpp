/* 
 * File:   BPTD.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 16 Апрель 2015 г., 21:34
 */

#ifndef BPTD_HPP
#define	BPTD_HPP

#include "../Record.hpp"
class RecordBPTD : public Record
{
public:

    struct DATA
    {
        std::string edid;

        struct BodyPart
        {
            std::string partName;
            std::string partNode;
            std::string _VATStarget;
            std::string _IKData_StartNode;
            std::string limbReplacementModel;
            std::string goreEffects_TargetBone;
            #pragma pack(push, 1)
            struct NodeData
            {
                float damageMultiplier;
                uint8_t flags;
                uint8_t partType;
                uint8_t healthPercent;
                int8_t actorValue;
                uint8_t toHitChance;
                uint8_t explodable_ExplosionChancePer;
                uint16_t explodable_DebrisCount;
                formid explodable_Debris; // FormID of a DEBR record, or null.
                formid explodableExplosion; // FormID of a EXPL record, or null.
                float trackingMaxAngle;
                float explodable_DebrisScale;
                int32_t severable_DebrisCount;
                formid severable_Debris;
                formid severable_Explosion;
                float severable_DebrisScale;
                float goreEffects_TranslateX;
                float goreEffects_TranslateY;
                float goreEffects_TranslateZ;
                float goreEffects_XRotation;
                float goreEffects_YRotation;
                float goreEffects_ZRotation;
                formid severable_ImpactDataset;
                formid explodable_ImpactDataset;
                uint8_t severable_DecalCount;
                uint8_t explodable_DecalCount;
                int8_t unused[2];
                float limbReplacementScale;
                
                enum Flag
                {
                    Severable = 0x01,
                    IKData = 0x02,
                    IKData_BipedData = 0x04,
                    Explodable = 0x08,
                    IKData_IsHead = 0x10,
                    IKData_Headtracking = 0x20,
                    ToHitChanceAbsolute = 0x40
                };
                enum PartType
                {
                    Torso = 0,
                    Head1,
                    Head2,
                    LeftArm1,
                    LeftArm2,
                    RightArm1,
                    RightArm2,
                    LeftLeg1,
                    LeftLeg2,
                    LeftLeg3,
                    RightLeg1,
                    RightLeg2,
                    RightLeg3,
                    Brain,
                    Weapon
                };
            } nodeData;
            #pragma pack(pop)
        };
        std::vector<BodyPart> bodyParts;
        formid ragdoll; // FormID of a RGDL record.
    } data;

    explicit RecordBPTD(const RecHeader &head) : Record(head) { Parse(); }

    RecordBPTD() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* BPTD_HPP */

