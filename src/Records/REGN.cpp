/* 
 * File:   REGN.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 17 Апрель 2015 г., 15:08
 */

#include "REGN.hpp"

using namespace std;

bool RecordREGN::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if(subType == "RCLR")
        data.mapColor = GetData<rgba>();
    else if(subType == "WNAM")
        data.worldspace = GetData<formid>();
    //---------------------------- Region Area Collection ----------------------
    else if(subType == "RPLI")
    {
        data.regionArea.push_back(DATA::RegionArea());
        data.regionArea.back().edgeFallOff = GetData<uint32_t>();
    }
    else if(subType == "RPLD")
        data.regionArea.back().regionPointListData.push_back(GetData<DATA::RegionArea::RegionPointListData>());
    //---------------------------- Region Data Entry Collection ----------------
    else if(subType == "RDAT")
    {
        data.regionDataEntrys.push_back(DATA::RegionDataEntry());
        data.regionDataEntrys.back().dataHeader = GetData<DATA::RegionDataEntry::DataHeader>();
    }
    else if(subType == "RDOT")
        data.regionDataEntrys.back().objects.push_back(GetData<DATA::RegionDataEntry::Object>());
    else if(subType == "RDMP")
        data.regionDataEntrys.back().grass.push_back(GetData<DATA::RegionDataEntry::Grass>());
    else if(subType == "RDMD")
        data.regionDataEntrys.back().musicType = GetData<uint32_t>();
    else if(subType == "RDMO")
        data.regionDataEntrys.back().music = GetData<formid>();
    else if(subType == "RDSD")
        data.regionDataEntrys.back().sounds.push_back(GetData<DATA::RegionDataEntry::Sound>());
    else if(subType == "RDWT")
        data.regionDataEntrys.back().weatherTypes.push_back(GetData<DATA::RegionDataEntry::WeatherType>());
    //--------------------------------------------------------------------------
    else return false;
    return true;
}
