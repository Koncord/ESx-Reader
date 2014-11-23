/* 
 * File:   recWEAP.cpp
 * Author: Koncord
 * 
 * Created on 18 Ноябрь 2014 г., 19:54
 */

#include "recWEAP.hpp"
#include "Reader.hpp"

#ifdef _DEBUG_
#include <iostream>
#endif

using namespace std;


WEAP::Weap weap;

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
    
    class recDATA: public SubRecord
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size, 2);
            
            esm->get(&weap.Value, 4);
            esm->get(&weap.Health, 4);
            esm->get(&weap.Weight, 4);
            esm->get(&weap.Damage, 2);
            esm->get(&weap.ClipRounds, 1);
        }
        std::string recordName() {return "DATA";}
    };
      class recCRDT: public SubRecord // Critical Damage Data
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size, 2);
            
            esm->get(&weap.CritDmg, 2);
            esm->ignoreBytes(2);
            esm->get(&weap.CritMult, 4);
            esm->get(&weap.CritFlags, 1);
            esm->ignoreBytes(3);
            esm->get(&weap.CritEffect, 4);
        }
        std::string recordName() {return "CRDT";}
    };
}
recWEAP::recWEAP()
{
    esm = Reader::getSingletonPtr();
    RegisterSubRecord(new WEAP::recEDID);
    RegisterSubRecord(new WEAP::recFULL);
    RegisterSubRecord(new WEAP::recDATA);
    RegisterSubRecord(new WEAP::recCRDT);
}

void recWEAP::parseData()
{
    uint32_t size;
    esm->get(&size, 8);
    esm->get(&weap.id, 4);
    esm->ignoreBytes(8);
    parseSubRecord();
    
#ifdef _DEBUG_DETAIL
    cout << "WEAP ID: 0x"<< hex << uppercase <<  weap.id
         << " EDID: " << weap.edid
         << " FULL: " << weap.full << endl
         << dec << " Value: " << weap.Value << endl
         << " Health: " << weap.Health << endl
         << " Weight: " << weap.Weight << endl
         << " Damage: " << weap.Damage << endl
         << " ClipRounds: " << (int) weap.ClipRounds << endl
         << " CritDmg: " << weap.CritDmg << endl
         << " Crit % Mult: " << weap.CritMult << endl
         << " CritFlags: " << (int) weap.CritFlags << endl
         << " CritEffect: " << weap.CritEffect << endl;
#endif
}