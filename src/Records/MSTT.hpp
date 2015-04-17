/* 
 * File:   MSTT.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 15:25
 */

#ifndef MSTT_HPP
#define	MSTT_HPP

#include "../Record.hpp"

class RecordMSTT : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        ObjectBounds objectBounds;
        Destruction destruction;
        formid sound;
        uint8_t unknown;
    } data;

    explicit RecordMSTT(const RecHeader &head) : Record(head) { Parse(); }

    RecordMSTT() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* MSTT_HPP */

