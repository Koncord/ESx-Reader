/* 
 * File:   CELL.hpp
 * Author: Koncord
 *
 * Created on 5 Декабрь 2014 г., 13:06
 */

#ifndef RECCELL_HPP
#define	RECCELL_HPP

#include "Record.hpp"

namespace CELL
{
    struct CELL
    {
        Record::Header head;
        std::string edid;
        std::string full;
        struct DATA
        {
            uint8_t flags;
            bool isInterior() { return flags & 0x0001;}
            bool HasWatter() { return flags & 0x0002;}
            bool CantTravel() { return flags & 0x0004;}
            bool PublicArea() { return flags & 0x0020;}
            bool HandChanged() { return flags & 0x0040;}
        }DATA;
    };
}

class recCELL: public Record
{
public:
    recCELL();
    void parseData();
    std::string recordName() {return "CELL";}
};

#endif	/* RECCELL_HPP */

