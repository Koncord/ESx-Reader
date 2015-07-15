/* 
 * File:   NPC_.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 4 Февраль 2015 г., 18:57
 */

#include "NPC_.hpp"
#include <iostream>

using namespace std;

bool RecordNPC_::DoParse()
{
    const string subType = GetLabel();
    
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "FULL")
        data.name = GetString();
    else if(ModelCollection()) {}
    else if(subType == "ACBS")
        data.configuration = GetData<Configuration>();
    else if(subType == "SNAM")
        data.factions.push_back(GetData<Faction>());
    else if(subType == "INAM")
        data.deathItemId = GetData<formid>();
    else if(subType == "VTCK")
        data.voiceId = GetData<formid>();
    else if(subType == "TPLT")
        data.templateId = GetData<formid>();
    else if(subType == "RNAM")
        data.raceId = GetData<formid>();
    else if(subType == "EITM")
        data.unarmedAttackEffectId = GetData<formid>();
    else if(subType == "EAMT")
        data.unarmedAttackEffectId = GetData<uint16_t>();
    else if(subType == "SCRI")
        data.scriptId = GetData<formid>();
    else if(DestructionData(&data.destruction)) {}
    else if(ItemCollection(&data.items)) { }
    else if(subType == "AIDT")
        data.aiData = GetData<AIData>();
    else if(subType == "PKID")
        data.packages.push_back(GetData<formid>());
    else if(subType == "CNAM")
        data.classId = GetData<formid>();
    else if(subType == "DATA")
    {
        uint16_t x = rawdata.pos;
        data.data = GetData<DATA::_DATA>();
        IgnoreBytes(subhead.dataSize - (rawdata.pos - x));
    }
    else if(subType == "DNAM")
        data.skills = GetData<DATA::DNAM>();
    else if(subType == "PNAM")
        data.headParts.push_back(GetData<formid>());
    else if(subType == "HNAM")
        data.hairId = GetData<formid>();
    else if(subType == "LNAM")
        data.hairLength = GetData<float>();
    else if(subType == "ENAM")
        data.eyes = GetData<formid>();
    else if(subType == "HCLR")
        data.hairColor = GetData<rgba>();
    else if(subType == "ZNAM")
        data.combatStyle = GetData<formid>();
    else if(subType == "NAM4")
        data.combatStyle = GetData<uint32_t>();
    else if(subType == "FGGS")
    {
        data.FaceGenGeometrySymmetric.reserve(subhead.dataSize);
        for(int i = 0; i < subhead.dataSize; i++)
        {
            data.FaceGenGeometrySymmetric.push_back(GetData<uint8_t>());
        }
    }
    else if(subType == "FGGA")
    {
        data.FaceGenGeometryAsymmetric.reserve(subhead.dataSize);
        for(int i = 0; i < subhead.dataSize; i++)
        {
            data.FaceGenGeometryAsymmetric.push_back(GetData<uint8_t>());
        }
    }
    else if(subType == "FGTS")
    {
        data.FaceGenTextureSymmetric.reserve(subhead.dataSize);
        for(int i = 0; i < subhead.dataSize; i++)
        {
            data.FaceGenTextureSymmetric.push_back(GetData<uint8_t>());
        }
    }
    else if(subType == "NAM5")
        data.unknown = GetData<uint16_t>();
    else if(subType == "SPLO")
        data.actorEffect = GetData<formid>();
    else if(subType == "NAM6")
        data.height = GetData<float>();
    else if(subType == "NAM7")
        data.weight = GetData<float>();
    else return false;
    return true;
}