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
        DESTRUCTION destruction;
        formid scriptId;
         #pragma pack(push, 1)
        struct OBND 
        {
            uint16_t x1, y1, z1;
            uint16_t x2, y2, z2;
        } obnd;

        struct _DATA
        {
          uint8_t flags;
          int8_t skill; // enum values (CTDA ???)
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

