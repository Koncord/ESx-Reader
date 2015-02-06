/* 
 * File:   subETYP.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 30 Январь 2015 г., 22:42
 */

#ifndef SUBETYP_HPP
#define	SUBETYP_HPP

#pragma pack(push, 1)
struct ETYP
{
    int32_t equipType;
    enum FLAGS
    {
        None = -1,
        BigGuns,
        EnergyWeapons,
        SmallGuns,
        MeleeWeapons,
        UnarmedWeapons,
        ThrownWeapons,
        Mine,
        BodyWear,
        HeadWear,
        HandWear,
        Chems,
        Stimpack,
        Food,
        Alcohol
    };
};
#pragma pack(pop)


#endif	/* SUBETYP_HPP */
