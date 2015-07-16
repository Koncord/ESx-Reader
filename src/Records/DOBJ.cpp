/* 
 * File:   DOBJ.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 21:17
 */

#include "DOBJ.hpp"

using namespace std;

bool RecordDOBJ::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "DATA")
        data.defaultObjects = GetData<DATA::DefaultObjects>();
    else return false;
    return true;
}
