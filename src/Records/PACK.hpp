/* 
 * File:   PACK.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 17 Апрель 2015 г., 16:05
 */

#ifndef PACK_HPP
#define	PACK_HPP

#include "../Record.hpp"

class RecordPACK : public Record
{
public:

    struct DATA
    {
        std::string edid;
        
    } data;

    explicit RecordPACK(const RecHeader &head) : Record(head) { Parse(); }

    RecordPACK() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* PACK_HPP */

