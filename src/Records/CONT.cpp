/* 
 * File:   CONT.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 31 Январь 2015 г., 20:00
 */

#include "CONT.hpp"

bool RecordCONT::DoParse()
{
    std::string subType = GetLabel();
    if (subType == "EDID")
        this->data.edid = this->GetString();
    else if (subType == "OBND")
        data.objectBounds = GetData<OBND>();
    else if(subType == "FULL")
        data.name = GetString();
    else if(ModelCollection()) {}
    else if(subType == "SCRI")
        data.scriptId = GetData<uint32_t>();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(subType == "SNAM" || subType == "QNAM")
        IgnoreSubRecord(); // ignore open/close SOUN records
    else if(ItemCollection(&data.items)){}
    else if(DestructionData(&data.destruction)) {}
    else return false;
    return true;
}
