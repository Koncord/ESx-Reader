/* 
 * File:   FACT.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 5 Февраль 2015 г., 0:21
 */

#include "FACT.hpp"

bool RecordFACT::DoParse()
{
    std::string subType = GetLabel();
    if (subType == "EDID")
        data.edid = GetString();
    else if (subType == "FULL")
        data.name = GetString();
    else if(subType == "XNAM")
        data.relation.push_back(GetData<XNAM>());
    else if(subType == "DATA")
    {
        data.data.flags1 = GetData<uint8_t>();
        if(subhead.dataSize > 2)
        {
            data.data.flags2 = GetData<uint8_t>();
            data.data.unused[0] = GetData<uint8_t>();
            data.data.unused[1] = GetData<uint8_t>();
        }
    }
    else if(subType == "CNAM")
        data.unused = GetData<float>();
    // ------------------ Rank collection --------------------------------------
    else if(subType == "RNAM")
    {
        data.ranks.push_back(DATA::RANKCOL());
        data.ranks.back().rankNumber = GetData<int32_t>();
    }
    else if(subType == "MNAM")
        data.ranks.back().male = GetString();
    else if(subType == "FNAM")
        data.ranks.back().female = GetString();
    else if(subType == "INAM")
        data.ranks.back().insignia = GetString();
    // -------------------------------------------------------------------------
    else return false;
    return true;
}
