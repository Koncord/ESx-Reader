/* 
 * File:   RecordECZN.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 20:36
 */

#ifndef ECZN_HPP
#define	ECZN_HPP

#include "../Record.hpp"

class RecordECZN : public Record
{
public:

    struct DATA
    {
        std::string edid;
        
        #pragma pack(push, 1)
        struct _DATA 
        {
            formid owner; // FormID of an NPC_ or FACT record, or null.
            int8_t rank;
            int8_t minLevel;
            uint8_t flags;
            uint8_t unused;
            enum Flag
            {
                NeverResets = 0x01,
                MatchPCBelowMinimumLevel = 0x02
            };
        } data;
        #pragma pack(pop)
    } data;

    explicit RecordECZN(const RecHeader &head) : Record(head) { Parse(); }

    RecordECZN() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* ECZN_HPP */

