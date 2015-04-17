/* 
 * File:   DOOR.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 20:27
 */

#ifndef DOOR_HPP
#define	DOOR_HPP

#include "../Record.hpp"

class RecordDOOR : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        uint8_t flags;
        enum Flag
        {
            Unknown = 0x01,
            AutomaticDoor = 0x02,
            Hidden = 0x04,
            MinimalUse = 0x08,
            SlidingDoor = 0x10
        };
        Destruction destruction;
        formid scriptId;
        ObjectBounds objectBounds;
    } data;

    explicit RecordDOOR(const RecHeader &head) : Record(head) { Parse(); }

    RecordDOOR() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* DOOR_HPP */

