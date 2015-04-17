/* 
 * File:   REGN.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 17 Апрель 2015 г., 15:08
 */

#ifndef REGN_HPP
#define	REGN_HPP

#include "../Record.hpp"

class RecordREGN : public Record
{
public:

    struct DATA
    {
        std::string edid;
        rgba mapColor;
        formid worldspace; // FormID of a WRLD record.
        struct RegionArea
        {
            uint32_t edgeFallOff;
            struct RegionPointListData
            {
                float x, y;
            };
            std::vector<RegionPointListData> regionPointListData;
        };
        std::vector<RegionArea> regionArea;
        
        struct RegionDataEntry
        {
            std::string mapName;
            uint32_t musicType;
            formid music; // FormID of a MUSC record.
            
#pragma pack(push, 1)
            struct DataHeader
            {
                uint32_t type;
                uint8_t flags;
                uint8_t unused;
                enum Type
                {
                    Unknown0 = 0,
                    Unknown1,
                    Objects,
                    Weather,
                    Map,
                    Land,
                    Grass,
                    Sound,
                    Unknown2,
                    Unknown3
                };
                enum Flag
                {
                    Override = 0x01
                };
            } dataHeader;
            struct Object
            {
                formid object; // FormID of a TREE, STAT or LTEX record.
                uint16_t parentIndex;
                uint16_t unused0;
                float density;
                uint8_t clustering;
                uint8_t minSlope;
                uint8_t maxSlope;
                uint8_t flags;
                uint16_t radiusWithRespectToParent;
                uint16_t radius;
                uint32_t unknown1;
                float maxHeight;
                float sink;
                float sinkVariance;
                float sizeVariance;
                uint16_t XAngleVariance;
                uint16_t YAngleVariance;
                uint16_t ZAngleVariance;
                uint8_t unknown2[6];
                enum Flag
                {
                    ConformToSlope,
                    PaintVertices,
                    SizeVarianceSign,
                    XSign,
                    YSign,
                    ZSign,
                    Tree,
                    HugeRock
                };
            };
            std::vector<Object> objects;
            
            struct Grass
            {
                formid grass; // FormID of a GRAS record.
                uint32_t unknown;
            };
            std::vector<Grass> grass;
            
            struct Sound
            {
                formid sound; // FormID of a SOUN record.
                uint32_t flags;
                uint32_t chance;
                enum Flag
                {
                    Pleasant = 0x00000001,
                    Cloudy = 0x00000002,
                    Rainy = 0x00000004,
                    Snowy = 0x00000008
                };
            };
            std::vector<Sound> sounds;
            
            struct WeatherType
            {
                formid weather; // FormID of a WTHR record.
                uint32_t chance;
                formid global; // FormID of a GLOB record, or null.
            };
            std::vector<WeatherType> weatherTypes;
            #pragma pack(pop)
        };
        std::vector<RegionDataEntry> regionDataEntrys;
    } data;

    explicit RecordREGN(const RecHeader &head) : Record(head) { Parse(); }

    RecordREGN() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* REGN_HPP */

