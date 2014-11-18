/* 
 * File:   recWEAP.cpp
 * Author: Koncord
 * 
 * Created on 18 Ноябрь 2014 г., 19:54
 */

#include "recWEAP.hpp"
#include "Reader.hpp"
#include <iostream>

using namespace std;

struct Weap
{
    uint64_t id;
    std::string edid;
    std::string full;
};

Weap weap;

Reader *esm = nullptr;

namespace WEAP
{
    
    class recEDID: public SubRecord
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size, 2);
            
            char *edid = new char[size];
            esm->get(edid, size);
            weap.edid = edid;
            delete[] edid;
        }
        std::string recordName() {return "EDID";}
    };

    class recFULL: public SubRecord // ingame name
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size, 2);
            
            char *full = new char[size];
            esm->get(full, size);
            weap.full = full;
            delete[] full;
        }
        std::string recordName() {return "FULL";}
    };
}
recWEAP::recWEAP()
{
    esm = Reader::getSingletonPtr();
    RegisterSubRecord(new WEAP::recEDID);
    RegisterSubRecord(new WEAP::recFULL);
}

void recWEAP::parseData()
{
    uint64_t size;
    esm->get(&size, 8);
    esm->get(&weap.id, 4);
    esm->ignoreBytes(8);
    parseSubRecord();
    
//#ifdef _DEBUG_
    cout << "WEAP ID: 0x"<< hex<< uppercase <<  weap.id
         << " EDID: " << weap.edid
         << " NAME: " << weap.full << endl;
//#endif
}