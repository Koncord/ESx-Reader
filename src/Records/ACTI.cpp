/* 
 * File:   ACTI.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 21:40
 */

#include "ACTI.hpp"

using namespace std;

bool RecordACTI::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(ModelCollection()) {}
    else if(subType == "SCRI")
        data.script = GetData<formid>();
    else if(DestructionData(&data.destruction)) {}
    else if(subType == "SNAM" || subType == "VNAM")
        IgnoreSubRecord();
    else if(subType == "RNAM")
        data.radioStation = GetData<formid>();
    else if(subType == "WNAM")
        data.waterType = GetData<formid>();
    else return false;
    return true;
}

