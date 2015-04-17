/* 
 * File:   PACK.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 17 Апрель 2015 г., 16:05
 */

#include "PACK.hpp"

using namespace std;

bool RecordPACK::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(ModelCollection()) {}
    else return false;
    return true;
}

