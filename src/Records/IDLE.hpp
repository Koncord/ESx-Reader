/* 
 * File:   IDLE.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 12 Апрель 2015 г., 17:38
 */

#ifndef IDLE_HPP
#define	IDLE_HPP

#include "../Record.hpp"
class RecordIDLE : public Record
{
public:

    struct DATA
    {
        std::string edid;
        ObjectBounds objectBounds;
        std::vector<CTDA> conditions;
        std::vector<formid> releatedIdleAnimations;
#pragma pack(push, 1)
        struct _DATA
        {
            uint8_t animationGroupSection;
            uint8_t loopingMin;
            uint8_t loopingMax;
            uint8_t unused1;
            uint16_t replayDelay;
            uint8_t flags;
            uint8_t unused2;
            enum Animation
            {
                Idle = 0,
                Movement,
                LEftArm,
                LeftHand,
                Weapon,
                WeaponUp,
                WeaponDown,
                SpecialIdle,
                WholeBody,
                UpperBody
            };
            enum Flag
            {
                NoAttacking = 0x01
            };
        } data;
#pragma pack(pop)
    } data;

    explicit RecordIDLE(const RecHeader &head) : Record(head) { Parse(); }

    RecordIDLE() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* IDLE_HPP */

