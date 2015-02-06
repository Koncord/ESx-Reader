/* 
 * File:   NPC_.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 4 Февраль 2015 г., 18:57
 */

#ifndef NPC__HPP
#define	NPC__HPP

#include "../Record.hpp"
#include "../Subrecords/subACBS.hpp"
#include "../Subrecords/subSNAM.hpp"
#include "../Subrecords/subAIDT.hpp"
#include "../Types.hpp"

class RecordNPC_ : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        DESTRUCTION destruction;
        ACBS configuration;
        std::vector<SNAM> factions;
        ITEMCOL items;
        AIDT aiData;
        float height;
        float weight;
        std::vector<formid> packages;
        std::vector<formid> headParts;
        std::vector<uint8_t> FaceGenGeometrySymmetric;
        std::vector<uint8_t> FaceGenGeometryAsymmetric;
        std::vector<uint8_t> FaceGenTextureSymmetric;
        uint32_t impactMaterialType;
        enum IMPACTMATTYPE
        {
            Stone = 0,
            Dirt,
            Grass,
            Glass,
            Metal,
            Wood,
            Organic,
            Cloth,
            Water,
            HollowMetal,
            OrganicBug,
            OrganicGlow
        };
        float hairLength;
        rgba hairColor;
        formid combatStyle;
        formid eyes;
        formid hairId;
        formid classId; // FormID of a CLAS record.
        formid deathItemId; // LVLI record.
        formid voiceId;
        formid templateId; // NPC_ or LVLN record.
        formid raceId;  // RACE record.
        formid unarmedAttackEffectId; // ENCH or SPEL record.
        formid actorEffect;
        uint16_t unarmedAttackAnimation;
        uint16_t unknown;
        formid scriptId;
    #pragma pack(push, 1)
    struct OBND
    {
        uint16_t x1, y1, z1;
        uint16_t x2, y2, z2;
    } obnd; 
    struct _DATA
    {
        int32_t baseHealth;
        uint8_t strength;
        uint8_t perception;
        uint8_t endurance;
        uint8_t charisma;
        uint8_t intelligence;
        uint8_t agility;
        uint8_t luck;
        //uint8_t unused; // Only appears in older record versions.
    } data;
    struct DNAM
    {
        uint8_t SVBarter;
        uint8_t SVBigGuns;
        uint8_t SVEnergyWeapons;
        uint8_t SVExplosives;
        uint8_t SVLockpick;
        uint8_t SVMedicine;
        uint8_t SVMeleeWeapons;
        uint8_t SVRepair;
        uint8_t SVScience;
        uint8_t SVSmallGuns;
        uint8_t SVSneak;
        uint8_t SVSpeech;
        uint8_t SVThrowing; // unused
        uint8_t SVUnarmed;
        
        uint8_t SOBarter;
        uint8_t SOBigGuns;
        uint8_t SOEnergyWeapons;
        uint8_t SOExplosives;
        uint8_t SOLockpick;
        uint8_t SOMedicine;
        uint8_t SOMeleeWeapons;
        uint8_t SORepair;
        uint8_t SOScience;
        uint8_t SOSmallGuns;
        uint8_t SOSneak;
        uint8_t SOSpeech;
        uint8_t SOThrowing; // unused
        uint8_t SOUnarmed;
        
    } skills;
    #pragma pack(pop)
    } data;
    
    explicit RecordNPC_(const RecHeader &head) : Record(head) { Parse(); }

    RecordNPC_() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* NPC__HPP */

