/* 
 * File:   STAT.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 21:57
 */

#ifndef STAT_HPP
#define	STAT_HPP

#include "../Record.hpp"

class RecordSTAT : public Record
{
public:

    struct DATA
    {
        std::string edid;
        #pragma pack(push, 1)
        struct OBND 
        {
            uint16_t x1, y1, z1;
            uint16_t x2, y2, z2;
        } obnd;
        #pragma pack(pop)
    } data;

    explicit RecordSTAT(const RecHeader &head) : Record(head) { Parse(); }

    RecordSTAT() : Record() { Parse(); }
    virtual bool DoParse();
};
#endif	/* STAT_HPP */

