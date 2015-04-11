/* 
 * File:   KEYM.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 5 Февраль 2015 г., 23:29
 */

#ifndef KEYM_HPP
#define	KEYM_HPP

#include "../Record.hpp"

class RecordKEYM : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        formid scriptId;
        Destruction destruction;
        OBND objectBounds;
        #pragma pack(push, 1)
        struct _DATA
        {
          uint32_t value;
          float weight;
        } data;
        #pragma pack(pop)
    } data;

    explicit RecordKEYM(const RecHeader &head) : Record(head) { Parse(); }

    RecordKEYM() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* KEYM_HPP */

