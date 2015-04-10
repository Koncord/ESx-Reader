/* 
 * File:   CELL.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 17:03
 */

#ifndef CELL_HPP
#define	CELL_HPP

#include "../Record.hpp"

class RecordCELL : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        uint8_t flags;
        enum FLAG
        {
            IsInteriorCell = 0x01,
            HasWater = 0x02,
            InvertFastTravelBehaviour = 0x04,
            NoLODWater = 0x08,
            Unknown = 0x10,
            PublicPlace = 0x20,
            HandChanged = 0x40,
            BehaveLikeExterior = 0x80
        };
        
        float waterHeight;
        std::vector<formid> region;
        formid encounterZone;
        formid climate;
        formid water;
        formid owner;           // ownership. FormID of a FACT, ACHR or NPC_ record.
        int32_t factionRank;    // ownership.
        struct LightTemplate
        {
            formid templateId;
            uint32_t inherit;
            enum InheritFlag
            {
                AmbientColor = 0x00000001,
                DirectionalColor = 0x00000002,
                FogColor = 0x00000004,
                FogNear = 0x00000008,
                FogFar = 0x00000010,
                DirectionalRotation = 0x00000020,
                DirectionalFade = 0x00000040,
                FogClipDistance = 0x00000080,
                FogPower = 0x00000100
            };
        }lightTemplate;
        #pragma pack(push, 1)
        struct Grid
        {
            int32_t x, y;
            uint32_t forceHideLand; //flags
            enum ForceHideLand
            {
                Quad1 = 0x00000001,
                Quad2 = 0x00000002,
                Quad3 = 0x00000004,
                Quad4 = 0x00000008
            };
        } grid;
        struct Lighting
        {
            uint32_t ambientColor;
            uint32_t directionalColor;
            uint32_t fogColor;
            float fogNear;
            float fogFar;
            int32_t directionalRotationXY;
            int32_t DirectionalRotationZ;
            float directionalFade;
            float fogClipDistance;
            float fogPower;
        } lighting;
        #pragma pack(pop)
    } data;

    explicit RecordCELL(const RecHeader &head) : Record(head) { Parse(); }

    RecordCELL() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* CELL_HPP */

