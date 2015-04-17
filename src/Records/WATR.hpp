/* 
 * File:   WATR.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 17 Апрель 2015 г., 15:46
 */

#ifndef WATR_HPP
#define	WATR_HPP

#include "../Record.hpp"

class RecordWATR : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        uint8_t flags;
        formid sound; // FormID of a SOUN record.
        formid actorEffect; // FormID of a SPEL record.
        uint16_t damage;
        enum Flag
        {
            CausesDamage = 0x01,
            Reflective = 0x02
        };
    } data;

    explicit RecordWATR(const RecHeader &head) : Record(head) { Parse(); }

    RecordWATR() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* WATR_HPP */

