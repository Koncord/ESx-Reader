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
            
            esm->get(&weap.ItmValue, 4);
            esm->get(&weap.ItmMaxCondition, 4);
            esm->get(&weap.ItmWeight, 4);
            esm->get(&weap.WeaponDamage, 2);
            esm->get(&weap.AmmoCapacity, 1);
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
            
            esm->get(&weap.CritDmgBonus, 2);
            esm->ignoreBytes(2);
            esm->get(&weap.CritChance, 4);
            esm->get(&weap.CritFlags, 1);
            esm->ignoreBytes(3);
            esm->get(&weap.CritSPELid, 4);
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
    uint64_t size;
    esm->get(&size, 8);
    esm->get(&weap.id, 8);
    esm->ignoreBytes(4);
    parseSubRecord();
    
//#ifdef _DEBUG_
    cout << "WEAP ID: 0x"<< hex << uppercase <<  weap.id
         << " EDID: " << weap.edid
         << " FULL: " << weap.full << endl
         << dec << " ItmValue: " << weap.ItmValue << endl
         << " ItmMaxCondition: " << weap.ItmMaxCondition << endl
         << " ItmWeight: " << weap.ItmWeight << endl
         << " WeaponDamage: " << weap.WeaponDamage << endl
         << " AmmoCapacity: " << (int) weap.AmmoCapacity << endl
         << " CritDmgBonus: " << weap.CritDmgBonus << endl
         << " CritChance: " << weap.CritChance << endl
         << " CritFlags: " << (int) weap.CritFlags << endl
         << " CritSPELid: " << (int) weap.CritSPELid << endl;
//#endif
}