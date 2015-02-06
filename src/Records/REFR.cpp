/* 
 * File:   REFR.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 5 Февраль 2015 г., 16:51
 */

#include "REFR.hpp"

bool RecordREFR::DoParse()
{
    std::string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else return false;
    return true;
}
