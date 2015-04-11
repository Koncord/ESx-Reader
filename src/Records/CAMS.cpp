/* 
 * File:   CAMS.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 19:08
 */

#include "CAMS.hpp"


using namespace std;

bool RecordCAMS::DoParse()
{
    string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(ModelCollection()) {}
    else if(subType == "MNAM")
        data.imageSpaceModifier = GetData<formid>();
    else return false;
    return true;
}
