/* 
 * File:   GLOB.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 31 Январь 2015 г., 23:58
 */

#include "GLOB.hpp"

bool RecordGLOB::DoParse()
{
    if (GetLabel() == "EDID")
        data.edid = this->GetString();
    else if (GetLabel() == "FNAM")
        data.type = GetData<char>();
    else if (GetLabel() == "FLTV")
        data.value = GetData<float>();
    else return false;
    return true;
}
