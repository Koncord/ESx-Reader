/* 
 * File:   RecordECZN.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 20:36
 */

#include "ECZN.hpp"

using namespace std;

bool RecordECZN::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else return false;
    return true;
}
