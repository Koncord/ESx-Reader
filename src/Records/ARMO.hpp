/* 
 * File:   ARMO.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 5 Февраль 2015 г., 14:59
 */

#ifndef ARMO_HPP
#define	ARMO_HPP

#include "../Record.hpp"
#include "../Subrecords/subBMDT.hpp"
#include "../Subrecords/subETYP.hpp"

class RecordARMO : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        std::string ragdollConstTempl;
        formid scriptId;
        formid objectEffectId; // ENCH or SPEL record.
        formid repairListId; // FLST record.
        formid bipedModelListId; // FLST record.
        BMDT bipedData;
        ETYP equipmentType;
        #pragma pack(push, 1)
        struct OBND 
        {
            uint16_t x1, y1, z1;
            uint16_t x2, y2, z2;
        } obnd;
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

    explicit RecordARMO(const RecHeader &head) : Record(head) { Parse(); }

    RecordARMO() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* ARMO_HPP */

