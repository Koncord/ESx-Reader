/* 
 * File:   FACT.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 5 Февраль 2015 г., 0:21
 */

#ifndef FACT_HPP
#define	FACT_HPP

#include "../Record.hpp"
#include "../Subrecords/subXNAM.hpp"

class RecordFACT : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        std::vector<Relation> relation;
        float unused;
        #pragma pack(push, 1)
        struct _DATA
        {
            uint8_t flags1;
            uint8_t flags2;
            uint8_t unused[2];
            
            enum FLAGS1
            {
                HiddenFromPC = 0x01,
                Evil = 0x02,
                SpecialCombat = 0x04
            };
            enum FLAGS2
            {
                TrackCrime = 0x01,
                AllowSell = 0x02
            };
        }data;
        #pragma pack(pop)
        struct RANKCOL
        {
            int32_t rankNumber;
            std::string male;
            std::string female;
            std::string insignia;
        };
        std::vector<RANKCOL> ranks;
        
    } data;

    explicit RecordFACT(const RecHeader &head) : Record(head) { Parse(); }

    RecordFACT() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* FACT_HPP */

