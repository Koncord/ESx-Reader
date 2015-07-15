/* 
 * File:   CLAS.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 5 Февраль 2015 г., 14:46
 */

#include "CLAS.hpp"

bool RecordCLAS::DoParse()
{
    const std::string subType = GetLabel();
    if (subType == "EDID")
        data.edid = GetString();
    else if (subType == "FULL")
        data.name = GetString();
    else if (subType == "DESC")
        data.description = GetString();
    else if (subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(subType == "ATTR")
    {
        for(int i = 0; i < 7; i++)
            data.attribute.push_back(GetData<uint8_t>());
    }
    else return false;
    return true;
}
