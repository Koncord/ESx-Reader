/* 
 * File:   PWAT.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 15:30
 */

#ifndef PWAT_HPP
#define	PWAT_HPP

#include "../Record.hpp"
class RecordPWAT : public Record
{
public:

    struct DATA
    {
        std::string edid;
        OBND objectBounds;
        #pragma pack(push, 1)
        struct _DATA
        {
            uint32_t flags;
            formid water; // FormID of a WATR record.
            enum Flag
            {
                Reflects = 0x00000001,
                ReflectsActors = 0x00000002,
                ReflectsLand = 0x00000004,
                ReflectsLODLand = 0x00000008,
                ReflectsLODBuildings = 0x00000010,
                ReflectsTrees = 0x00000020,
                ReflectsSky = 0x00000040,
                ReflectsDynamicObjects = 0x00000080,
                ReflectsDeadBodies = 0x00000100,
                Refracts = 0x00000200,
                RefractsActors = 0x00000400,
                RefractsLand = 0x00000800,
                Unknown1 = 0x00001000,
                Unknown2 = 0x00002000,
                Unknown3 = 0x00004000,
                Unknown4 = 0x00008000,
                RefractsDynamicObjects = 0x00010000,
                RefractsDeadBodies = 0x00020000,
                SilhouetteReflections = 0x00040000,
                Unknown5 = 0x00080000,
                Unknown6 = 0x00100000,
                Unknown7 = 0x00200000,
                Unknown8 = 0x00400000,
                Unknown9 = 0x00800000,
                Unknown10 = 0x01000000,
                Unknown11 =0x02000000,
                Unknown12 = 0x04000000,
                Unknown13 = 0x08000000,
                Depth = 0x10000000,
                ObjectTextureCoordinates = 0x20000000,
                Unknown14 = 0x40000000,
                NoUnderwaterFog = 0x80000000
            };
        } data;
        #pragma pack(pop)
    } data;

    explicit RecordPWAT(const RecHeader &head) : Record(head) { Parse(); }

    RecordPWAT() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* PWAT_HPP */

