/* 
 * File:   ACRE.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 2 Июль 2015 г., 12:12
 */

#include "ACRE.hpp"

using namespace std;

bool RecordACRE::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "NAME")
        data.baseId = GetData<formid>();
    else if(subType == "XEZN")
        data.encounterZoneId = GetData<formid>();
    else if(subType == "XRGD" || subType == "XRGB") // skip unknown
        IgnoreSubRecord();
    else if(subType == "XPRD")
        data.idleTime = GetData<float>();
    else if(subType == "XPPA") // marker
        IgnoreSubRecord();
    else if(subType == "INAM")
        data.idleId = GetData<formid>();
    else if(ScriptCollection(&data.script)) {}
    else if(subType == "TNAM")
        data.topicId = GetData<formid>();
    else if(subType == "XLCM")
        data.levelModifier = GetData<int32_t>();
    else if(subType == "XOWN")
        data.ownerId = GetData<formid>();
    else if(subType == "XRNK")
        data.factionRank = GetData<int32_t>();
    else if(subType == "XMRC")
        data.merchantContainerId = GetData<formid>();
    else if(subType == "XCNT")
        data.count = GetData<int32_t>();
    else if(subType == "XRDS")
        data.radius = GetData<float>();
    else if(subType == "XHLP")
        data.health = GetData<float>();
    else if(subType == "XDCR")
        IgnoreSubRecord(); // skip decals;
    else if(subType == "XLKR")
        data.linkedRefId = GetData<formid>();
    else if(subType == "XCLP")
        data.linkedReferenceColor[1] = GetData<DATA::LinkedReferenceColor>();
    else if(subType == "XAPD")
        data.parentActivateOnly = GetData<uint8_t>();
    else if(subType == "XAPR")
        data.activateParentRefs.push_back(GetData<DATA::ActivateParentRef>());
    else if(subType == "XESP")
        data.enableParent = GetData<DATA::EnableParent>();
    else if(subType == "XEMI")
        data.emittanceId = GetData<formid>();
    else if(subType == "XMBR")
        data.multiBoundRefId = GetData<formid>();
    else if(subType == "XIBS")
        IgnoreSubRecord(); // marker flag??
    else if(subType == "XSCL")
        data.scale = GetData<float>();
    else if(subType == "DATA")
        data.positionRotation = GetData<DATA::PositionRotation>();
    else return false;
    return true;
}
