/* 
 * File:   ARMA.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 5 Февраль 2015 г., 15:32
 */

#ifndef ARMA_HPP
#define	ARMA_HPP

#include "../Record.hpp"
#include "../Subrecords/subBMDT.hpp"
#include "../Subrecords/subETYP.hpp"

class RecordARMA : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        BMDT bipedData;
        ETYP equipmentType;
        #pragma pack(push, 1)
        OBND objectBounds;
        struct _DATA
        {
            int32_t value;
            int32_t maxCondition;
            float weight;
        } data;
        struct DNAM
        {
          int16_t ar; // Value is divided by 100 by game. (RESISTANCE ???)
          bool modulatesVoice;
          uint8_t unused[1];
        } dnam;
        #pragma pack(pop)
        
    } data;

    explicit RecordARMA(const RecHeader &head) : Record(head) { Parse(); }

    RecordARMA() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* ARMA_HPP */

