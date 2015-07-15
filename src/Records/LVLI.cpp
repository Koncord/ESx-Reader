/* 
 * File:   LVLI.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 20:53
 */

#include "LVLI.hpp"

using namespace std;

bool RecordLVLI::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "LVLD")
        data.chanceNone = GetData<uint8_t>();
    else if(subType == "LVLF")
        data.flags = GetData<uint8_t>();
    else if(subType == "LVLG")
        data.global = GetData<formid>();
    //-----------------Leveled List Entry Subrecord Collection------------------
    else if(subType == "LVLO")
    {
        data.leveledListEntry.push_back(DATA::LeveledListEntry());
        data.leveledListEntry.back().baseData = GetData<DATA::LeveledListEntry::BaseData>();
    }
    else if(subType == "COED")
        data.leveledListEntry.back().extraData = GetData<DATA::LeveledListEntry::ExtraData>();
    //--------------------------------------------------------------------------
    else if(ModelCollection()) {}
    else return false;
    return true;
}
