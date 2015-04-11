/* 
 * File:   LVLI.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 20:53
 */

#ifndef LVLI_HPP
#define	LVLI_HPP

#include "../Record.hpp"
class RecordLVLI : public Record
{
public:

    struct DATA
    {
        std::string edid;
        OBND objectBounds;
        uint8_t chanceNone;
        uint8_t flags;
        formid global; // FormID of a GLOB record.
        enum Flag
        {
            CalculateFromAllLevels = 0x01, // player's level
            CalculateForEachItemInCount = 0x02,
            UseAll = 0x04
        };
        #pragma pack(push, 1)
        struct LeveledListEntry
        {
            struct BaseData
            {
                int16_t level;
                int16_t unused;
                formid reference; // FormID of a ARMO, AMMO, MISC, WEAP, BOOK, LVLI, KEYM, ALCH or NOTE record.
                int16_t count;
                int16_t unused1;
            } baseData;
            struct ExtraData
            {
                formid owner;
                union
                {
                    formid globalVariable;
                    uint32_t RequiredRank;
                };
                float itemCondition;
            } extraData;
        };
        #pragma pack(pop)
        std::vector<LeveledListEntry> leveledListEntry;
    } data;

    explicit RecordLVLI(const RecHeader &head) : Record(head) { Parse(); }

    RecordLVLI() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* LVLI_HPP */

