/* 
 * File:   ItemCollection.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 10 Апрель 2015 г., 21:37
 */

#ifndef ITEMCOLLECTION_HPP
#define	ITEMCOLLECTION_HPP
#include "../Types.hpp"
#include "../debug_macros.hpp"

#pragma pack(push, 1)
struct Item
{
    todo( rename structures )
    struct CNTO
    {
        formid itemId; // ARMO, AMMO, MISC, WEAP, BOOK, LVLI, KEYM, ALCH, NOTE, MSTT or STAT record.
        int32_t count;
    }item;
    struct COED
    {
        uint32_t ownerId;
        uint32_t special; // FormID of a GLOB record, an integer representing the required rank, or null.
        float condition;
    }extra;
};
#pragma pack(pop)
typedef std::vector<Item> Items;

#endif	/* ITEMCOLLECTION_HPP */

