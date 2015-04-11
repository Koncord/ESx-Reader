/* 
 * File:   FURN.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 20:02
 */

#include "FURN.hpp"

using namespace std;

bool RecordFURN::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<OBND>();
    else if (subType == "SCRI") 
        data.script = GetData<formid>();
    else if (subType == "MNAM") 
        data.markerFlags = GetRawData();
    else if(DestructionData(&data.destruction)) {}
    else if(ModelCollection()) {}
    else return false;
    return true;
}
