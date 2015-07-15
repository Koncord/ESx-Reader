/* 
 * File:   CSTY.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 16 Апрель 2015 г., 22:05
 */

#include "CSTY.hpp"

using namespace std;

bool RecordCSTY::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "CSTD")
        data.advanced_Standard = GetData<DATA::Advanced_Standard>();
    else if(subType == "CSAD")
        data.advanced_Advanced = GetData<DATA::Advanced_Advanced>();
    else if(subType == "CSSD")
        data.simple = GetData<DATA::Simple>();
    else return false;
    return true;
}
