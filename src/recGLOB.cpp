/* 
 * File:   recGLOB.cpp
 * Author: Koncord
 * 
 * Created on 5 Декабрь 2014 г., 17:16
 */

#include "recGLOB.hpp"
#include "Reader.hpp"

static GLOB::GLOB glob;
static Reader *esm = nullptr;

namespace GLOB
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
            glob.edid = str;
            delete[] str;
        }
        std::string recordName() {return "EDID";} 
    };
    
    class recFNAM: public SubRecord
    {
        public:
        void parseData()
        {

            uint16_t size;
            esm->get(&size);
            
            esm->get(&glob.fnam);
        }
        std::string recordName() {return "FNAM";} 
    };
    
    class recFLTV: public SubRecord
    {
        public:
        void parseData()
        {

            uint16_t size;
            esm->get(&size);
            
            esm->get(&glob.fltv);
        }
        std::string recordName() {return "FLTV";} 
    };
}

recGLOB::recGLOB()
{
    esm = Reader::getSingletonPtr();
    RegisterSubRecord(new GLOB::recEDID);
    RegisterSubRecord(new GLOB::recFLTV);
    RegisterSubRecord(new GLOB::recFNAM);
}

void recGLOB::parseData()
{
    glob.head = parseHead();
    parseSubRecord();
    esm->globals.emplace_back(new GLOB::GLOB(glob));
}