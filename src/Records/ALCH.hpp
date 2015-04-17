/* 
 * File:   ALCH.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 4 Февраль 2015 г., 23:47
 */

#ifndef ALCH_HPP
#define	ALCH_HPP

#include "../Record.hpp"
#include "../Subrecords/subETYP.hpp"
class RecordALCH : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        formid scriptId;
        ETYP equipmentType;
        Destruction destruction;
        Effect effect;
        float weight;
        ObjectBounds objectBounds;
    #pragma pack(push, 1)
        struct ENIT
        {
            int32_t value;
            uint8_t flags;
            uint8_t unused[3];
            formid withdrawlEffect; // SPEL record, or null.
            float addictionChance;
            formid soundConsume; // not needed in VMP
            
            enum FLAGS
            {
                NoAutoCalc = 0x01,
                FoodItem = 0x02,
                Medicine = 0x04
            };
        } effectData;
    #pragma pack(pop)

    } data;

    explicit RecordALCH(const RecHeader &head) : Record(head) { Parse(); }

    RecordALCH() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* ALCH_HPP */

