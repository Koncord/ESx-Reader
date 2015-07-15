/* 
 * File:   RACE.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 17 Апрель 2015 г., 13:38
 */

#ifndef RACE_HPP
#define	RACE_HPP

#include "../Record.hpp"
#include "../Subrecords/subXNAM.hpp"

class RecordRACE : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        std::string description;
        std::vector<Relation> relations;
        formid older;
        formid younger;
        float faceGenMainClamp;
        float faceGenFaceClamp;
        std::vector<formid> hairs;
        std::vector<formid> eyes;
        struct SexIds
        {
            formid male;
            formid female;
        }voices, defaultHairStyles;
        struct DefaultHairColors
        {
            uint8_t male;
            uint8_t female;
            enum DefaultHairColor
            {
                Bleached = 0,
                Brown,
                Chocolate,
                Platinum,
                Cornsilk,
                Suede,
                Pecan,
                Auburn,
                Ginger,
                Honey,
                Gold,
                Rosewood,
                Black,
                Chestnut,
                Steel,
                Champagne

            };
        } defaultHairColors;
        #pragma pack(push, 1)
        struct _DATA
        {
            struct SkillBoost
            {
                int8_t skill;
                int8_t boost;
            }   skillBoost[7];
            int8_t unused0[2];
            float maleHeight;
            float femaleHeight;
            float maleWeight;
            float femaleWeight;
            uint32_t flags;
            enum Flag
            {
                Playable = 0x00000001,
                Unknown = 0x00000002,
                Child = 0x00000004
            };
        } data;
        #pragma pack(pop)
        
        NOTE(we need FaceGen geometric?)
    } data;

    explicit RecordRACE(const RecHeader &head) : Record(head) { Parse(); }

    RecordRACE() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* RACE_HPP */

