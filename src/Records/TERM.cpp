/* 
 * File:   TERM.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 1 Февраль 2015 г., 14:27
 */

#include "TERM.hpp"
#include <stdexcept>
bool RecordTERM::DoParse()
{
    std::string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<OBND>();
    else if(subType == "FULL")
        data.name = GetString();
    else if(ModelCollection()){}
    else if(subType == "SCRI")
        data.scriptId = GetData<formid>();
    else if(DestructionData(&data.destruction)) {}
    else if(subType == "DESC")
        data.description = GetString();
    else if(subType == "SNAM")
        IgnoreSubRecord(); // Skip SOUN
    else if(subType == "PNAM")
        data.passwordNoteId = GetData<formid>();
    else if(subType == "DNAM")
        data.dnam = GetData<DATA::DNAM>();
    // ----------------------- Menu Item Subrecord Collection ------------------
    else if(subType == "ITXT")
    {
        data.items.push_back(DATA::MENUITM());
        data.items.back().itemText = GetString();
    }
    else if(subType == "RNAM")
        data.items.back().resultText = GetString();
    else if(subType == "ANAM")
        data.items.back().flags = GetData<uint8_t>();
    else if(subType == "INAM")
        data.items.back().displayNoteId = GetData<formid>();
    else if(subType == "TNAM")
        data.items.back().subMenuId = GetData<formid>();
    else if(ScriptCollection(&data.items.back().script)) { }
    else if(ConditionsData(&data.items.back().conditions)) { }
    //--------------------------------------------------------------------------
    else return false;
    return true;
}
