/* 
 * File:   CONT.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 31 Январь 2015 г., 20:00
 */

#ifndef CONT_HPP
#define	CONT_HPP

#include "../Group.hpp"
#include "../Record.hpp"

class RecordCONT : public Record
{
public:
    struct DATA
    {
        std::string edid;
        std::string name;
        uint32_t scriptId;
        Items items;
        Destruction destruction;
        ObjectBounds objectBounds;
#pragma pack(push, 1)
        struct _DATA
        {
            uint8_t flags;
            float weight;
            enum FLAG
            {
                Unknown = 0x01,
                Respawns = 0x02
            };
        }data;
#pragma pack(pop)

    } data;
    explicit RecordCONT(const RecHeader &head) : Record(head){Parse(); }
    RecordCONT() : Record() {Parse();}
    virtual bool DoParse();
};


#endif	/* CONT_HPP */
