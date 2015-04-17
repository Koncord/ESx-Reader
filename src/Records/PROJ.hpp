/* 
 * File:   PROJ.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 21:27
 */

#ifndef PROJ_HPP
#define	PROJ_HPP

#include "../Record.hpp"
class RecordPROJ : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        ObjectBounds objectBounds;
        Destruction destruction;
        uint32_t soundLevel;
        enum soundLevel
        {
            Loud = 0,
            Normal,
            Silent
        };
    #pragma pack(push, 1)
        struct _DATA
        {
            uint16_t flags;
            uint16_t type;
            float gravity;
            float speed;
            float range;
            formid light; // FormID of a LIGH record, or null.
            formid muzzleFlashLight; // FormID of a LIGH record, or null.
            float tracerChance;
            float explosionAltTriggerProximity;
            float explosionAltTriggerTimer;
            formid explosion;
            formid sound;
            float muzzleFlashDuration;
            float fadeDuration;
            float impactForce;
            formid soundCountdown; // FormID of a SOUN record, or null.
            formid soundDisable; // FormID of a SOUN record, or null.
            formid defaultWeaponSource; // FormID of a WEAP record, or null.
            enum Flag
            {
                Hitscan = 0x0001,
                Explosion = 0x0002,
                AltTrigger = 0x0004,
                MozzleFlash = 0x0008,
                Unknown = 0x0010,
                CanBeDisabled = 0x0020,
                CanBePickedUp = 0x0040,
                Supersonic = 0x0080,
                PinsLimbs = 0x0100,
                PassThroughSmallTransparent = 0x0200
            };
            enum Type
            {
                Unknown1 = 0,
                Missile,
                Lobber,
                Unknown2,
                Beam,
                Unknown3,
                Unknown4,
                Unknown5,
                Flame
            };
        } data;
    #pragma pack(pop)
    } data;

    explicit RecordPROJ(const RecHeader &head) : Record(head) { Parse(); }

    RecordPROJ() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* PROJ_HPP */

