/* 
 * File:   BOOK.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 4 Февраль 2015 г., 18:38
 */

#ifndef BOOK_HPP
#define	BOOK_HPP

#include "../Record.hpp"

class RecordBOOK : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        std::string description;
        Destruction destruction;
        formid scriptId;
        OBND objectBounds;
        #pragma pack(push, 1)

        struct _DATA
        {
          uint8_t flags;
          //NOTE("enum values (CTDA ?)")
          int8_t skill;
          int32_t value;
          float weight;
        } data;
        #pragma pack(pop)
    } data;

    explicit RecordBOOK(const RecHeader &head) : Record(head) { Parse(); }

    RecordBOOK() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* BOOK_HPP */

