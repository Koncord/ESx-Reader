/* 
 * File:   SCPT.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 4 Февраль 2015 г., 18:22
 */

#include "SCPT.hpp"

bool RecordSCPT::DoParse()
{
    if (GetLabel() == "EDID")
        data.edid = GetString();
    else if(ScriptCollection(&data.script)) {}
    else return false;
    return true;
}
