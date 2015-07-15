/* 
 * File:   RACE.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 17 Апрель 2015 г., 13:38
 */

#include "RACE.hpp"

using namespace std;

bool RecordRACE::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "DESC")
        data.description = GetString();
    else if(subType == "XNAM")
        data.relations.push_back(GetData<Relation>());
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(subType == "ONAM")
        data.older = GetData<formid>();
    else if(subType == "YNAM")
        data.younger = GetData<formid>();
    else if(subType == "VTCK")
        data.voices.push_back(GetData<formid>());
    else if(subType == "DNAM")
        data.defaultHairStyles.push_back(GetData<formid>());
    else if(subType == "CNAM")
        data.defaultHairColors.push_back(GetData<uint8_t>());
    else if(subType == "PNAM")
        data.faceGenMainClamp = GetData<float>();
    else if(subType == "UNAM")
        data.faceGenFaceClamp = GetData<float>();
    else if(subType == "HNAM")
        data.hairs.push_back(GetData<formid>());
    else if(subType == "ENAM")
         data.eyes.push_back(GetData<formid>());
    
    else if(subType == "ATTR" || subType == "NAM0" || subType == "MNAM" ||
            subType == "INDX" || subType == "ICON" || subType == "MICO" ||
            subType == "FNAM" || subType == "FGGS" || subType == "FGGA" ||
            subType == "FGTS" || subType == "SNAM")
        IgnoreSubRecord();
    else if(ModelCollection()) {}
    else return false;
    return true;
}
