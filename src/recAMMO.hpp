/* 
 * File:   recAMMO.hpp
 * Author: Koncord
 *
 * Created on 5 Декабрь 2014 г., 17:53
 */

#ifndef RECAMMO_HPP
#define	RECAMMO_HPP

#include "Record.hpp"

namespace AMMO
{
    struct AMMO
    {
        Record::Header head;
        std::string edid;
        std::string full;
        std::string onam;
        
        struct DATA
        {
            float speed;
            uint8_t flags;
            uint32_t value;
            uint8_t rounds;
        } DATA;
    };
}

class recAMMO: public Record
{
public:
    recAMMO();
    void parseData();
    std::string recordName() {return "AMMO";}
};

#endif	/* RECAMMO_HPP */

