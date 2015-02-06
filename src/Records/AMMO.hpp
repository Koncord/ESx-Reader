/* 
 * File:   AMMO.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 1 Февраль 2015 г., 1:40
 */

#ifndef AMMO_HPP
#define	AMMO_HPP

#include "../Record.hpp"

class RecordAMMO : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        std::string shortName;
        DESTRUCTION destruction;
        
        #pragma pack(push, 1)
        struct OBND 
        {
            uint16_t x1, y1, z1;
            uint16_t x2, y2, z2;
        } obnd;
        struct _DATA
        {
            float speed;
            uint8_t flags;
            uint8_t unused[3];
            uint32_t value;
            uint8_t clipRounds;
            enum FLAG
            {
                IgnoresNormalWeaponResistance = 0x01,
                NonPlayable = 0x02
            };
        }data;
#pragma pack(pop)
    } data;

    explicit RecordAMMO(const RecHeader &head) : Record(head) { Parse(); }

    RecordAMMO() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* AMMO_HPP */
