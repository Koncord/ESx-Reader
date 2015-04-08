/* 
 * File:   DOOR.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 20:27
 */

#include "DOOR.hpp"

using namespace std;

bool RecordDOOR::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.obnd = GetData<DATA::OBND>();
    else if(subType == "FULL")
        data.name = GetString();
    else if(SkipModelData()) {}
    else if(DestructionData(&data.destruction)) {}
    else if(subType == "SCRI")
        data.scriptId = GetData<formid>();
    else if(subType == "SNAM" || subType == "ANAM" || subType == "BNAM" )
        IgnoreSubRecord();
    else if(subType == "FNAM")
        data.flags = GetData<uint8_t>();
    else return false;
    return true;
}
