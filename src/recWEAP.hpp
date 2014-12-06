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
    struct WEAP
    {
        Record::Header head;
        uint64_t id;
        std::string edid;
        std::string full;
        uint64_t scri;
        struct DATA
        {
            int32_t Value;
            int32_t Health;
            float Weight;
            int16_t Damage;
            uint8_t ClipRounds;
        } DATA;
        struct CRDT
        {
            uint16_t CritDmg;
            float CritMult;
            uint8_t CritFlags;
            uint32_t CritEffect;
        } CRDT;
        struct DNAM 
        {
            //uint8_t AnimType;
            float Speed;
            float Reach;
            uint8_t Flags;
            uint8_t AmmoUse;
            float MinSpread;
            float MaxSpread;
            float MinRange;
            float MaxRange;
            uint32_t OnHit;
            uint32_t Flags2;
            float ReloadTime;
        } DNAM;
        
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

