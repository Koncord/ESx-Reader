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
        Record::Header head;
        uint64_t id;
        std::string edid;
        std::string full;
        uint64_t scri;
        //************* DATA ****************
        int Value;
        int Health;
        float Weight;
        int16_t Damage;
        uint8_t ClipRounds;
        //************* CRDT ****************
        uint16_t CritDmg;
        float CritMult;
        uint8_t CritFlags;
        uint32_t CritEffect;
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

