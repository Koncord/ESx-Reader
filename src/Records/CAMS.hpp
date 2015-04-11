/* 
 * File:   CAMS.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 10 Апрель 2015 г., 19:08
 */

#ifndef CAMS_HPP
#define	CAMS_HPP

#include "../Record.hpp"

class RecordCAMS: public Record
{
public:

    struct DATA
    {
        std::string edid;
        formid imageSpaceModifier; // FormID of an IMAD record.
        struct _DATA
        {
            uint32_t action;
            uint32_t location;
            uint32_t target;
            uint32_t flags;
            float playerTimeMult;
            float targetTimeMult;
            float globalTimeMult;
            float maxTime;
            float minTime;
            float targetPercentBetweenActors;
            enum Action
            {
                Shoot = 0,
                Fly,
                Hit,
                Zoom
            };
            enum class Location
            {
                Attacker = 0,
                Projectile,
                Target
            };
            using Target = Location;
            enum Flag
            {
                PositionFollowsLocation = 0x00000001,
                RotationFollowsTarget = 0x00000002,
                DontFollowBone = 0x00000004,
                FirstPersonCamera = 0x00000008,
                NoTracer = 0x00000010,
                StartAtTimeZero = 0x00000020
            };
        } data;
    } data;
    explicit RecordCAMS(const RecHeader &head) : Record(head) { Parse(); }

    RecordCAMS() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* CAMS_HPP */

