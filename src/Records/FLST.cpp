/* 
 * File:   FLST.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 5 Февраль 2015 г., 16:25
 */

#include "FLST.hpp"

bool RecordFLST::DoParse()
{
    if (GetLabel() == "EDID")
        data.edid = GetString();
    else if(GetLabel() == "LNAM")
        data.formids.push_back(GetData<formid>());
    else return false;
    return true;
}
