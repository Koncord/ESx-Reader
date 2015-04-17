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
        std::vector<formid> voices;
        std::vector<formid> defaultHairStyles;
        std::vector<uint8_t> defaultHairColors;
        float faceGenMainClamp;
        float faceGenFaceClamp;
        std::vector<formid> hairs;
        std::vector<formid> eyes;
        #pragma pack(push, 1)
        struct _DATA
        {
            struct SkillBoost
            {
                int8_t skill;
                int8_t boost;
            }   skillBoost1, skillBoost2, skillBoost3, 
                skillBoost4, skillBoost5, skillBoost6, skillBoost7;
            int8_t unused0[2];
            float maleHeight;
            float femaleHeight;
            uint32_t flags;
            enum Flag
            {
                Playable = 0x00000001,
                Unknown = 0x00000002,
                Child = 0x00000004
            };
        } data;
        #pragma pack(pop)
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
        NOTE(we need FaceGen geometric?)
    } data;

    explicit RecordRACE(const RecHeader &head) : Record(head) { Parse(); }

    RecordRACE() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* RACE_HPP */

