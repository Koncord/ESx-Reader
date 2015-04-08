/* 
 * File:   RADS.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 20:58
 */

#ifndef RADS_HPP
#define	RADS_HPP

#include "../Record.hpp"

class RecordRADS : public Record
{
public:

    struct DATA
    {
        std::string edid;
        #pragma pack(push, 1)
        struct _DATA 
        {
            uint32_t triggerThreshold;
            formid actorEffect; // FormID of a SPEL record.
        } data;
        #pragma pack(pop)
    } data;

    explicit RecordRADS(const RecHeader &head) : Record(head) { Parse(); }

    RecordRADS() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* RADS_HPP */

