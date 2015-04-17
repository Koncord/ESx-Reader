/* 
 * File:   LVLN_LVLC.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 20:34
 */

#ifndef LVLN_LVLC_HPP
#define	LVLN_LVLC_HPP

#include "../Record.hpp"
class RecordLVLN_LVLC : public Record
{
public:

    struct DATA
    {
        std::string edid;
        ObjectBounds objectBounds;
        uint8_t chanceNone;
        uint8_t flags;
        enum Flag
        {
            CalculateFromAllLevels = 0x01, // player's level
            CalculateForEachItemInCount = 0x02
        };
    #pragma pack(push, 1)
        struct LeveledListEntry
        {
            struct BaseData
            {
                int16_t level;
                int16_t unused;
                formid reference; // FormID of a NPC_ for LVLN or CREA for LVLC
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

    explicit RecordLVLN_LVLC(const RecHeader &head) : Record(head) { Parse(); }

    RecordLVLN_LVLC() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* LVLN_LVLC_HPP */

