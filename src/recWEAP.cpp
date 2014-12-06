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


WEAP::WEAP weap;

static Reader *esm = nullptr;

namespace WEAP
{
    
    class recEDID: public SubRecord
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
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
            esm->get(&size);
            
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
            esm->get(&size);
            
            esm->get(&weap.DATA.Value);
            esm->get(&weap.DATA.Health);
            esm->get(&weap.DATA.Weight);
            esm->get(&weap.DATA.Damage);
            esm->get(&weap.DATA.ClipRounds);
        }
        std::string recordName() {return "DATA";}
    };
    class recCRDT: public SubRecord // Critical Damage Data
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
            esm->get(&weap.CRDT.CritDmg);
            esm->ignoreBytes(2);
            esm->get(&weap.CRDT.CritMult);
            esm->get(&weap.CRDT.CritFlags);
            esm->ignoreBytes(3);
            esm->get(&weap.CRDT.CritEffect);
        }
        std::string recordName() {return "CRDT";}
    };
    class recDNAM: public SubRecord // Critical Damage Data
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size, 2);
            esm->ignoreBytes(4); // Animation Type
            esm->get(&weap.DNAM.Speed); // Animation mult
            esm->get(&weap.DNAM.Reach);
            esm->get(&weap.DNAM.Flags); // Ignores Normal Weapon Resistance, 
                                           // Is Automatic, Has Scope, Can't Drop,
                                           // Hide Backpack, Embedded Weapon,
                                           // Don't Use 1st Person IS Animations, Non-Playable
            esm->ignoreBytes(1); // Grip Animation
            esm->get(&weap.DNAM.AmmoUse);
            esm->ignoreBytes(1); // Reload Animation
            esm->get(&weap.DNAM.MinSpread);
            esm->get(&weap.DNAM.MaxSpread);
            esm->ignoreBytes(4); // Unknown
            esm->ignoreBytes(4); // Sight FOV
            esm->ignoreBytes(4); // Unknown
            esm->ignoreBytes(4); // Projectile
            esm->ignoreBytes(1); // VATS To-Hit Chance    
            esm->ignoreBytes(1); // Attack Animation
            esm->ignoreBytes(1); // Projectile Count
            esm->ignoreBytes(1); // Embedded Weapon - Actor Value
            esm->get(&weap.DNAM.MinRange); // MinRange
            esm->get(&weap.DNAM.MaxRange); // MaxRange
            esm->get(&weap.DNAM.OnHit);
            esm->get(&weap.DNAM.Flags2);
            esm->ignoreBytes(4); // Animation Attack Multiplier
            esm->ignoreBytes(4); // Fire Rate
            esm->ignoreBytes(4); // Override - Action Points
            esm->ignoreBytes(4); // Rumble - Left Motor Strength
            esm->ignoreBytes(4); // Rumble - Right Motor Strength
            esm->ignoreBytes(4); // Rumble - Duration
            esm->ignoreBytes(4); // Override - Damage to Weapon Mult
            esm->ignoreBytes(4); // Attack Shots/Sec
            esm->get(&weap.DNAM.ReloadTime);
            esm->ignoreBytes(4); // Jam Time
            esm->ignoreBytes(4); // Aim Arc
            esm->ignoreBytes(4); // Skill
            esm->ignoreBytes(4); // Rumble - Pattern
            esm->ignoreBytes(4); // Rumble - Wavelength
            esm->ignoreBytes(4); // Limb Dmg Mult
            esm->ignoreBytes(4); // Resist Type
            esm->ignoreBytes(4); // Sight Usage
            esm->ignoreBytes(4); // Semi-Automatic Fire Delay Min
            esm->ignoreBytes(4); // Semi-Automatic Fire Delay Max
        }
        std::string recordName() {return "DNAM";}
    };
}
recWEAP::recWEAP()
{
    esm = Reader::getSingletonPtr();
    RegisterSubRecord(new WEAP::recEDID);
    RegisterSubRecord(new WEAP::recFULL);
    RegisterSubRecord(new WEAP::recDATA);
    RegisterSubRecord(new WEAP::recCRDT);
    RegisterSubRecord(new WEAP::recDNAM);
}

void recWEAP::parseData()
{
    weap.head = parseHead();
    parseSubRecord();
    esm->weapons.emplace_back(new WEAP::WEAP(weap));
#ifdef _DEBUG_DETAIL
    cout << "WEAP ID: 0x"<< hex << uppercase <<  weap.head.formid
         << " EDID: " << weap.edid
         << " FULL: " << weap.full << endl
         << dec << " Value: " << weap.DATA.Value << endl
         << " Health: " << weap.DATA.Health << endl
         << " Weight: " << weap.DATA.Weight << endl
         << " Damage: " << weap.DATA.Damage << endl
         << " ClipRounds: " << (int) weap.DATA.ClipRounds << endl
         << " CritDmg: " << weap.CRDT.CritDmg << endl
         << " Crit % Mult: " << weap.CRDT.CritMult << endl
         << " CritFlags: " << (int) weap.CRDT.CritFlags << endl
         << " CritEffect: " << weap.CRDT.CritEffect << endl
         << "isAutomatic: " << (weap.DNAM.Flags == 0x02 ? "true" : "false") << endl
         << "MinRange: " << weap.DNAM.MinRange << endl
         << "MaxRange: " << weap.DNAM.MaxRange << endl;
    getchar();
#endif
}