/* 
 * File:   recKEYM.cpp
 * Author: Sega DreamCast
 * 
 * Created on 5 Декабрь 2014 г., 19:40
 */

#include "recKEYM.hpp"
#include "Reader.hpp"

static KEYM::KEYM keym;
static Reader *esm = nullptr;

namespace KEYM
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
            keym.edid = str;
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
            keym.full = str;
            delete[] str;
        }
        std::string recordName() {return "FULL";}
    };
    
     class recDATA: public SubRecord
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
            esm->get(&keym.DATA.value);
            esm->get(&keym.DATA.weight);
        }
        std::string recordName() {return "DATA";}
    };
}

recKEYM::recKEYM()
{
    esm = Reader::getSingletonPtr();
    
    RegisterSubRecord(new KEYM::recEDID);
    RegisterSubRecord(new KEYM::recFULL);
    RegisterSubRecord(new KEYM::recDATA);
}

void recKEYM::parseData()
{
    keym.head = parseHead();
    
    parseSubRecord();
    
    esm->keys.emplace_back(new KEYM::KEYM(keym));
}