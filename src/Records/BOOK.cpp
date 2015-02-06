/* 
 * File:   BOOK.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 4 Февраль 2015 г., 18:38
 */

#include "BOOK.hpp"

using namespace std;

bool RecordBOOK::DoParse()
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
    else if(subType == "MICO" || subType == "ICON") 
        IgnoreSubRecord();
    else if(subType == "SCRI")
        data.scriptId = GetData<formid>();
    else if(subType == "DESC")
        data.description = GetString();
    else if(subType == "YNAM" || subType == "ZNAM")
        IgnoreSubRecord();
    else if(subType == "DATA")
    {
        data.data = GetData<DATA::_DATA>();
    }
    else return false;
    return true;
}
