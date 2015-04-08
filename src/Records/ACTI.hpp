/* 
 * File:   ACTI.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 21:40
 */

#ifndef ACTI_HPP
#define	ACTI_HPP

#include "../Record.hpp"

class RecordACTI : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        formid script;
        formid radioStation;
        formid waterType;
        DESTRUCTION destruction;
        #pragma pack(push, 1)
        struct OBND 
        {
            uint16_t x1, y1, z1;
            uint16_t x2, y2, z2;
        } obnd;
        #pragma pack(pop)
    } data;

    explicit RecordACTI(const RecHeader &head) : Record(head) { Parse(); }

    RecordACTI() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* ACTI_HPP */

