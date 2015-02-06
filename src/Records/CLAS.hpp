/* 
 * File:   CLAS.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 5 Февраль 2015 г., 14:46
 */

#ifndef CLAS_HPP
#define	CLAS_HPP

#include "../Record.hpp"

class RecordCLAS : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        std::string description;
        std::vector<uint8_t> attribute; // from Strength to Luck
        #pragma pack(push, 1)
        struct _DATA
        {
            int32_t TagSkill1;
            int32_t TagSkill2;
            int32_t TagSkill3;
            int32_t TagSkill4;
            uint32_t flags;
            uint32_t buysOrSellsAndServices;
            int8_t teaches;
            uint8_t maximumTrainingLevel;
            uint8_t unused[2];
            
            enum FLAGS
            {
                Playable = 0x00000001,
                Guard = 0x00000002
            };
        }data;
        #pragma pack(pop)
        
    } data;

    explicit RecordCLAS(const RecHeader &head) : Record(head) { Parse(); }

    RecordCLAS() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* CLAS_HPP */

