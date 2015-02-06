/* 
 * File:   KEYM.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 5 Февраль 2015 г., 23:29
 */

#include "KEYM.hpp"

bool RecordKEYM::DoParse()
{
    std::string subType = GetLabel();
    
    if(subType == "EDID")
        data.edid = GetString();
    else if (subType == "OBND")
        data.obnd = GetData<DATA::OBND>();
    else if (subType == "FULL")
        data.name = GetString();
    else if (SkipModelData()) {}
    else if (subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if (subType == "SCRI")
        data.scriptId = GetData<formid>();
    else if (DestructionData(&data.destruction)) {}
    else if (subType == "YNAM" || subType == "ZNAM")
        IgnoreSubRecord();
    else if (subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else return false;
    return true;
}

