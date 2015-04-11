/* 
 * File:   PWAT.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 15:30
 */

#include "PWAT.hpp"

using namespace std;

bool RecordPWAT::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<OBND>();
    else if(subType == "DNAM")
        data.data = GetData<DATA::_DATA>();
    else if(ModelCollection()) {}
    else return false;
    return true;
}
