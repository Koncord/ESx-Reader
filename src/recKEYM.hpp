/* 
 * File:   recKEYM.hpp
 * Author: Sega DreamCast
 *
 * Created on 5 Декабрь 2014 г., 19:40
 */

#ifndef RECKEYM_HPP
#define	RECKEYM_HPP

#include "Record.hpp"

namespace KEYM
{
    struct KEYM
    {
        Record::Header head;
        std::string edid;
        std::string full;
        struct
        {
            int32_t value;
            float weight;
        }DATA;
    };
}

class recKEYM: public Record
{
public:
    recKEYM();
    void parseData();
    std::string recordName() {return "KEYM";}
};

#endif	/* RECKEYM_HPP */

