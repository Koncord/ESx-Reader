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
        ObjectBounds objectBounds;
    } data;

    explicit RecordSTAT(const RecHeader &head) : Record(head) { Parse(); }

    RecordSTAT() : Record() { Parse(); }
    virtual bool DoParse();
};
#endif	/* STAT_HPP */

