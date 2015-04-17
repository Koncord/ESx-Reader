/* 
 * File:   COBJ.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 20:26
 */

#ifndef COBJ_HPP
#define	COBJ_HPP

#include "../Record.hpp"
class RecordCOBJ : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        ObjectBounds objectBounds;
        formid script; // FormID of a SCPT record.
#pragma pack(push, 1)
        struct _DATA
        {
          int32_t value;
          float weight;
        } data;
#pragma pack(pop)
    } data;

    explicit RecordCOBJ(const RecHeader &head) : Record(head) { Parse(); }

    RecordCOBJ() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* COBJ_HPP */

