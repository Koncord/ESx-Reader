/* 
 * File:   WRLD.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 2 Июль 2015 г., 14:44
 */

#ifndef WRLD_HPP
#define	WRLD_HPP

#include "../Record.hpp"

class RecordWRLD : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        formid encounterZoneId;
        formid parentWorldspaceId;

        struct ParentWorldspaceFlags
        {
            uint8_t flags;
            uint8_t unknown;

            enum Flags
            {
                UseLandData = 0x01,
                UseLODData = 0x02,
                UseMapData = 0x04,
                UseWaterData = 0x08,
                UseClimateData = 0x10,
                UseImageSpaceData = 0x20,
                Unknown = 0x40,
                NeedsWaterAdjustment = 0x80
            };
        } parentWorldspaceFlags;
        
        formid climateId;
        formid waterId;
        uint8_t flags;
        enum Flags
        {
            SmallWorld = 0x01,
            CantFastTravel = 0x02,
            Unknown0 = 0x04,
            Unknown1 = 0x08,
            NoLodWater = 0x10,
            NoLodNoise = 0x20,
            DontAllowNPCFallDamage = 0x40,
            NeedsWaterAdjustment = 0x80
        };
    } data;

    explicit RecordWRLD(const RecHeader &head) : Record(head)
    {
        Parse();
    }

    RecordWRLD() : Record()
    {
        Parse();
    }
    virtual bool DoParse();
};

#endif	/* WRLD_HPP */

