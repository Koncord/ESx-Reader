/* 
 * File:   ENCH.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 10 Апрель 2015 г., 22:20
 */

#ifndef ENCH_HPP
#define	ENCH_HPP

#include "../Record.hpp"
class RecordENCH : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        #pragma pack(push, 1)
        struct EffectData
        {
            TODO(Check this)
            int32_t value;
            uint8_t flags;
            uint8_t unused[3];
            formid withdrawlEffect; // SPEL record, or null.
            float addictionChance;
            formid soundConsume;
            
            enum FLAGS
            {
                NoAutoCalc = 0x01,
                FoodItem = 0x02,
                Medicine = 0x04
            };
        } effectData;
        #pragma pack(pop)
        std::vector<Effect> effects;
    } data;

    explicit RecordENCH(const RecHeader &head) : Record(head) { Parse(); }

    RecordENCH() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* ENCH_HPP */

