/* 
 * File:   TACT.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 21:52
 */

#ifndef TACT_HPP
#define	TACT_HPP

#include "../Record.hpp"

class RecordTACT : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        formid script;
        DESTRUCTION destruction;
        #pragma pack(push, 1)
        struct OBND 
        {
            uint16_t x1, y1, z1;
            uint16_t x2, y2, z2;
        } obnd;
        #pragma pack(pop)
    } data;

    explicit RecordTACT(const RecHeader &head) : Record(head) { Parse(); }

    RecordTACT() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* TACT_HPP */

