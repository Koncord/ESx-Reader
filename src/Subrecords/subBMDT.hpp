/* 
 * File:   BMDT.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 5 Февраль 2015 г., 15:08
 */

#ifndef SUBBMDT_HPP
#define	SUBBMDT_HPP
#include "../Types.hpp"
#pragma pack(push, 1)
struct BMDT
{
    uint32_t bipedFlags;
    uint8_t GeneralFlags;
    uint8_t unused[3];
    enum BIPEDFLAG
    {
        Head =          0x00000001,
        Hair =          0x00000002,
        UpperBody =     0x00000004,
        LeftHand =      0x00000008,
        RightHand =     0x00000010,
        Weapon =        0x00000020,
        PipBoy =        0x00000040,
        Backpack =      0x00000080,
        Necklace =      0x00000100,
        Headband =      0x00000200,
        Hat =           0x00000400,
        EyeGlasses =    0x00000800,
        NoseRing =      0x00001000,
        Earrings =      0x00002000,
        Mask =          0x00004000,
        Choker =        0x00008000,
        MouthObject =   0x00010000,
        BodyAddOn1 =    0x00020000,
        BodyAddOn2 =    0x00040000,
        BodyAddOn3 =    0x00080000,
    };
    enum GENERALFLAG
    {
        Unknown1 = 0x01,
        Unknown2 = 0x02,
        Unknown3 = 0x04,
        Unknown4 = 0x08,
        Unknown5 = 0x10,
        PowerArmor = 0x20,
        NonPlayable = 0x40,
        Heavy = 0x80
    };
};
#pragma pack(pop)
#endif	/* SUBBMDT_HPP */

