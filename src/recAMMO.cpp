/* 
 * File:   recAMMO.cpp
 * Author: Koncord
 * 
 * Created on 5 Декабрь 2014 г., 17:53
 */

#include "recAMMO.hpp"
#include "Reader.hpp"

static AMMO::AMMO ammo;
static Reader *esm;

namespace AMMO
{
    class recEDID: public SubRecord
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
            char *str = new char[size];
            esm->get(str, size);
            ammo.edid = str;
            delete[] str;
        }
        std::string recordName() {return "EDID";} 
    };
    
    class recFULL: public SubRecord // ingame name
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
            char *str = new char[size];
            esm->get(str, size);
            ammo.full = str;
            delete[] str;
        }
        std::string recordName() {return "FULL";}
    };
    
    class recONAM: public SubRecord // ingame short name
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
            char *str = new char[size];
            esm->get(str, size);
            ammo.onam = str;
            delete[] str;
        }
        std::string recordName() {return "ONAM";}
    };
    class recDATA: public SubRecord // ingame short name
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
            esm->get(&ammo.DATA.speed);
            esm->get(&ammo.DATA.flags);
            esm->get(&ammo.DATA.value);
            esm->get(&ammo.DATA.rounds);
        }
        std::string recordName() {return "DATA";}
    }; 
}

recAMMO::recAMMO()
{
    esm = Reader::getSingletonPtr();
    
    RegisterSubRecord(new AMMO::recEDID);
    RegisterSubRecord(new AMMO::recFULL);
    RegisterSubRecord(new AMMO::recONAM);
    RegisterSubRecord(new AMMO::recDATA);
}

void recAMMO::parseData()
{
    ammo.head = parseHead();
    
    parseSubRecord();
    
    esm->ammo.emplace_back(new AMMO::AMMO(ammo));
}
