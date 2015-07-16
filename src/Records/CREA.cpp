/* 
 * File:   CREA.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 17 Апрель 2015 г., 14:19
 */

#include "CREA.hpp"

using namespace std;

bool RecordCREA::DoParse()
{

    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "OBND")
        data.objectBounds = GetData<ObjectBounds>();
    else if(subType == "SPLO")
        data.actorEffects.push_back(GetData<formid>());
    else if(subType == "EITM")
        data.unarmedAttackEffect = GetData<formid>();
    else if(subType == "EAMT")
        data.unarmedAttackAnimation = GetData<uint16_t>();
    else if(subType == "NIFZ" || subType == "NIFT")
        IgnoreSubRecord();
    else if(subType == "ACBS")
        data.configuration = GetData<Configuration>();
    else if(subType == "SNAM")
        data.factions.push_back(GetData<Faction>());
    else if(subType == "INAM")
        data.deathItem = GetData<formid>();
    else if(subType == "VTCK")
        data.voice = GetData<formid>();
    else if(subType == "TPLT")
        data._template = GetData<formid>();
    else if(DestructionData(&data.destruction)) {}
    else if(subType == "SCRI")
        data.script = GetData<formid>();
    else if(ItemCollection(&data.items)) {}
    else if(subType == "AIDT")
        data.aiData = GetData<AIData>();
    else if(subType == "PKID")
        data.packages.push_back(GetData<formid>());
    else if(subType == "KFFZ")
        data.animations.push_back(GetString());
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(subType == "RNAM")
        data.attackReach = GetData<uint8_t>();
    else if(subType == "ZNAM")
        data.combatStyle = GetData<formid>();
    else if(subType == "PNAM")
        data.bodyPartData = GetData<formid>();
    else if(subType == "TNAM")
        data.turningSpeed = GetData<float>();
    else if(subType == "BNAM")
        data.baseScale = GetData<float>();
    else if(subType == "WNAM")
        data.footWeight = GetData<float>();
    else if(subType == "NAM4")
        data.impactMaterialType = GetData<uint32_t>();
    else if(subType == "NAM5")
        data.soundLevel = GetData<uint32_t>();
    else if(subType == "CSCR")
        data.inheritsSoundsFrom = GetData<formid>();
    else if(subType == "CNAM")
        data.impactDataset =  GetData<formid>();
    else if(subType == "LNAM")
        data.MeleeWeaponList = GetData<formid>();
    //-------------------------- Sound Type Collection -------------------------
    else if(subType == "CSDT")
    {
        data.soundTypes.push_back(DATA::SoundType());
        data.soundTypes.back().type = GetData<uint32_t>();
    }
    else if(subType == "CSDI")
        data.soundTypes.back().sounds.push_back(GetData<formid>());
    else if(subType == "CSDC")
        data.soundTypes.back().soundChances.push_back(GetData<uint8_t>());
    //--------------------------------------------------------------------------
    else if(ModelCollection()) {}
    else return false;
    return true;
}

