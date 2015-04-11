/* 
 * File:   FURN.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 10 Апрель 2015 г., 20:02
 */

#ifndef FURN_HPP
#define	FURN_HPP

#include "../Record.hpp"

class RecordFURN : public Record
{
public:

    struct DATA
    {
        std::string edid;
        OBND objectBounds;
        std::string name;
        formid script;
        Destruction destruction;
        std::vector<uint8_t> markerFlags;
    } data;

    explicit RecordFURN(const RecHeader &head) : Record(head) { Parse(); }

    RecordFURN() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* FURN_HPP */

