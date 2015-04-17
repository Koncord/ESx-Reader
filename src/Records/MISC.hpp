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
        Destruction destruction;
        ObjectBounds objectBounds;
    #pragma pack(push, 1)
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

