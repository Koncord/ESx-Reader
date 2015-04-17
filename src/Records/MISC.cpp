/* 
 * File:   MISC.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 4 Февраль 2015 г., 23:18
 */

#include "MISC.hpp"

using namespace std;

bool RecordMISC::DoParse()
{
    string subType = GetLabel();
    
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "FULL")
        data.name = GetString();
    else if(ModelCollection()) {}
    else if(subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if(subType == "SCRI")
         data.scriptId = GetData<formid>();
    else if(DestructionData(&data.destruction)) {}
    else if(subType == "YNAM" || subType == "ZNAM")
        IgnoreSubRecord();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else return false;
    return true;
}

