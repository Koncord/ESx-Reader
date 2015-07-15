/* 
 * File:   REFR.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 5 Февраль 2015 г., 16:51
 */

#include "REFR.hpp"

bool RecordREFR::DoParse()
{
    static int magic_flag = 0;
    const std::string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "RCLR")
    {
        if(magic_flag == 0)
        {
            data.linkedReferenceColor[0] = GetData<DATA::LinkedReferenceColor>();
            magic_flag = 1;
        }
        else
            IgnoreSubRecord();
    }
    else if(subType == "NAME")
        data.baseId = GetData<formid>();
    else if(subType == "XEZN")
        data.encounterZoneId = GetData<formid>();
    else if(subType == "XRGD" || subType == "XRGB") // skip unknown
        IgnoreSubRecord();
    else if(subType == "XPRM")
        data.primitive = GetData<DATA::Primitive>();
    else if(subType == "XTRI")
        data.collisionLayer = GetData<uint32_t>();
    else if(subType == "XMBP") // marker
        IgnoreSubRecord();
    else if(subType == "XMBO")
        data.boundHalfExtents = GetData<DATA::BoundHalfExtents>();
    else if(subType == "XTEL")
        data.teleportDestination = GetData<DATA::TeleportDestination>();
    else if(subType == "XMRK") // marker
    {
        magic_flag = 2;
        IgnoreSubRecord();
    }
    else if(subType == "FNAM")
        data.mapMarkerFlags = GetData<uint8_t>();
    else if(subType == "FULL")
        data.mapMarkerName = GetString();
    else if(subType == "TNAM")
        data.mapMarkerData =  GetData<DATA::MapMarkerData>();
    else if(subType == "XTRG")
        data.targetId =  GetData<formid>();
    else if(subType == "XLCM")
        data.levelModifier = GetData<int32_t>();
    else if(subType == "XPRD")
        data.idleTime = GetData<float>();
    else if(subType == "XPPA")
    {
        magic_flag = 3;
        IgnoreSubRecord();
    }
    else if(subType == "INAM")
        data.idleId = GetData<formid>();
    else if(ScriptCollection(&data.script)) {}
    else if(subType == "TNAM" && magic_flag == 3)
        data.topicId = GetData<formid>();
    else if(subType == "XRDO")
        data.radioData = GetData<DATA::RadioData>();
    else if(subType == "XOWN")
        data.ownerId = GetData<formid>();
    else if(subType == "XRNK")
        data.factionRank = GetData<int32_t>();
    else if(subType == "XLOC")
        data.lockData = GetData<DATA::LockData>();
    else if(subType == "XCNT")
        data.count = GetData<int32_t>();
    else if(subType == "XRDS")
        data.radius = GetData<float>();
    else if(subType == "XHLP")
        data.health = GetData<float>();
    else if(subType == "XRAD")
        data.radiation = GetData<float>();
    else if(subType == "XCHG")
        data.charge = GetData<float>();
    else if(subType == "XAMT")
        data.ammoTypeId = GetData<formid>();
    else if(subType == "XAMC")
        data.ammoCount = GetData<int32_t>();
    else if(subType == "XPWR")
        data.waterReflectionsOrRefractions.push_back(GetData<DATA::WaterReflectionOrRefraction>());
    else if(subType == "XLTW")
        data.litWaterIds.push_back(GetData<formid>());
    else if(subType == "XDCR") // linked deacals
        IgnoreSubRecord();
    else if(subType == "XLKR")
        data.linkedRefId = GetData<formid>();
    else if(subType == "XCLP")
        data.linkedReferenceColor[1] = GetData<DATA::LinkedReferenceColor>();
    else if(subType == "XAPD")
        data.flags = GetData<uint8_t>();
    else if(subType == "XAPR")
        data.activateParentRefs.push_back(GetData<DATA::ActivateParentRef>());
    else if(subType == "XESP")
        data.enableParent = GetData<DATA::EnableParent>();
    else if(subType == "XEMI")
        data.emittanceId = GetData<formid>();
    else if(subType == "XMBR")
        data.multiBoundRefId = GetData<formid>();
    else if(subType == "XACT")
        data.actionFlag = GetData<uint32_t>();
    else if(subType == "ONAM" && subType == "XIBS")
    {
        magic_flag = 4;
        IgnoreSubRecord();
    }
    else if(subType == "XNDP")
        data.navigationDoorLink = GetData<DATA::NavDoorLink>();
    else if(subType == "XPOD")
        data.portalRooms.push_back(GetData<formid>());
    else if(subType == "XPLT") // portal data. incomplete
        IgnoreSubRecord();
    else if(subType == "XSED") // speed tree seed
        IgnoreSubRecord();
    else if(subType == "XRMR")
        data.linkedRoomCount = GetData<uint32_t>();
    else if(subType == "XLRM")
        data.linkedRefId = GetData<formid>();
    else if(subType == "XOCP")
        data.occlusionPlaneData = GetData<DATA::OcclusionPlaneData>();
    else if(subType == "XORD")
        data.linkedOcclusionPlanes = GetData<DATA::LinkedOcclusionPlanes>();
    else if(subType == "XLOD") // distant lod data
        IgnoreSubRecord();
    else if(subType == "XSCL")
        data.scale = GetData<float>();
    else if(subType == "DATA")
        data.positionRotation = GetData<DATA::PositionRotation>();
    else return false;
    return true;
}
