/* 
 * File:   COBJ.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 20:26
 */

#include "COBJ.hpp"

using namespace std;

bool RecordCOBJ::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if(subType == "SCRI")
        data.script = GetData<formid>();
    else if(subType == "YNAM" || subType == "ZNAM")
        IgnoreSubRecord();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(ModelCollection()) {}
    else return false;
    return true;
}

