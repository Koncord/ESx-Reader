/* 
 * File:   MISC.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 4 Февраль 2015 г., 23:18
 */

#ifndef MISC_HPP
#define	MISC_HPP

#include "../Record.hpp"

class RecordMISC : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        
        formid scriptId;
        DESTRUCTION destruction;
    #pragma pack(push, 1)
        struct OBND
        {
           uint16_t x1, y1, z1;
           uint16_t x2, y2, z2;
        } obnd; 
        struct _DATA
        {
            uint32_t value;
            float weight;
        } data;
    #pragma pack(pop)

    } data;

    explicit RecordMISC(const RecHeader &head) : Record(head) { Parse(); }

    RecordMISC() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* MISC_HPP */

