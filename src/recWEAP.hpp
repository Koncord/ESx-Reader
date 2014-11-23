/* 
 * File:   recWEAP.hpp
 * Author: Koncord
 *
 * Created on 18 Ноябрь 2014 г., 19:54
 */

#ifndef RECWEAP_HPP
#define	RECWEAP_HPP

#include "Record.hpp"

namespace WEAP
{
    struct Weap
    {
        uint64_t id;
        std::string edid;
        std::string full;
        uint64_t scri;
        //************* DATA ****************
        int ItmValue;
        int ItmMaxCondition;
        float ItmWeight;
        int16_t WeaponDamage;
        uint8_t AmmoCapacity;
        //************* CRDT ****************
        uint16_t CritDmgBonus;
        float CritChance;
        uint8_t CritFlags;
        uint32_t CritSPELid;
    };
}

class recWEAP: public Record
{
public:
    recWEAP();
    void parseData();
    std::string recordName() {return "WEAP";}
};


#endif	/* RECWEAP_HPP */

