/* 
 * File:   ModelCollection.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 21:41
 */

#include "ModelCollection.hpp"

#include "../Record.hpp"

bool Record::ModelCollection()
{
    const std::string subType = GetLabel();
    if (
            subType == "MODL" || subType == "MODB" ||
            subType == "MODT" || subType == "MODS" ||
            subType == "MODD" ||
            subType == "MOD2" || subType == "MO2T" ||
            subType == "MO2S" ||
            subType == "MOD3" || subType == "MO3T" ||
            subType == "MO3S" || subType == "MOSD" ||
            subType == "MOD4" || subType == "MO4T" ||
            subType == "MO4S"
        )
    {
        IgnoreSubRecord();
        return true;
    }
    return false;
}