/* 
 * File:   INGR.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 10 Апрель 2015 г., 20:25
 */

#ifndef INGR_HPP
#define	INGR_HPP

#include "../Record.hpp"
#include "../Subrecords/CollectionEffect.hpp"

class RecordINGR : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        OBND objectBounds;
        formid script;
        int32_t equipmentType;
        float weight;
        std::vector<Effect> effects;
        #pragma pack(push, 1)
        struct EffectData
        {
            int32_t value;
            uint8_t flags;
            int8_t unused[3];
            enum Flags
            {
                NoAutoCalculation = 0x01,
                FoodItem = 0x02
            };
        }effectData;
        #pragma pack(pop)
    } data;

    explicit RecordINGR(const RecHeader &head) : Record(head) { Parse(); }

    RecordINGR() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* INGR_HPP */

