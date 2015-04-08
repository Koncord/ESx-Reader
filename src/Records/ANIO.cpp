/* 
 * File:   ANIO.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 22:23
 */

#include "ANIO.hpp"

using namespace std;

bool RecordANIO::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "DATA")
        data.animation = GetData<formid>();
    else if(SkipModelData()) {}
    else return false;
    return true;
}
