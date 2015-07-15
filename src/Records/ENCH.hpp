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
            uint32_t type;
            uint8_t unused0[8];
            uint8_t Flag;
            uint8_t unused1[3];
            
            enum TYPE
            {
                Unknown0 = 0x00,
                Unknown1 = 0x01,
                Weapon = 0x02,
                Apparel = 0x03
            };

            enum FLAGS
            {
                NoAutoCalculate = 0x01,
                HideEffect = 0x04
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

