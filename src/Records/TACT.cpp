/* 
 * File:   TACT.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 21:52
 */

#include "TACT.hpp"

using namespace std;

bool RecordTACT::DoParse()
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
    else return false;
    return true;
}
