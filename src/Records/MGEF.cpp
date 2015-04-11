/* 
 * File:   MGEF.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 21:59
 */

#include "MGEF.hpp"

using namespace std;

bool RecordMGEF::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "DESC")
        data.description = GetString();
    else if(subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if(ModelCollection()) {}
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else return false;
    return true;
}


