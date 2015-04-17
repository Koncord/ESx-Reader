/* 
 * File:   STAT.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 21:57
 */

#include "STAT.hpp"

using namespace std;

bool RecordSTAT::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(ModelCollection()) {}
    else return false;
    return true;
}


