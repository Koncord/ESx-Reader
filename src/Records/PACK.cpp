/* 
 * File:   PACK.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 17 Апрель 2015 г., 16:05
 */

#include "PACK.hpp"

using namespace std;

bool RecordPACK::DoParse()
{
    static bool magicFlag = 0;
    static int level = 0;
    string subType = GetLabel();
    static CTDA condition;
    
    if (level == -1) // markers level
    {
        if(subType == "PKED")
            level = 1;
        else if(subType == "PUID")
            level = 2;
        else if(subType == "PKAM")
            level = 2;
        else if(subType == "POBA")
            level = 3;
    }
    else if(level == 0)
    {
        if(subType == "EDID")
            data.edid = GetString();
        else if(subType == "PKDT")
            data.general = GetData<DATA::General>();
        else if(subType == "PLDT")
        {
            magicFlag = true;
            data.locations.push_back(DATA::LocationCol());
            data.locations.back().location1 = GetData<DATA::Location>();
        }
        else if(subType == "PLD2")
        {
            if(magicFlag)
            {
                magicFlag = false;
                data.locations.back().location2 = GetData<DATA::Location>();
            }
            else
                data.location2 = GetData<DATA::Location>();
        }
        else if(subType == "PSDT")
            data.schedule = GetData<DATA::Schedule>();
        else if(subType == "PTDT")
            data.target1 = GetData<DATA::Target>();
        else if(ConditionsData(&condition))
            data.conditions.push_back(condition);
        else if(subType == "IDLF")
            data.idleAnimationFlags = GetData<uint8_t>();
        else if(subType == "IDLC")
            data.idleAnimationCount = GetData<uint32_t>();
        else if(subType == "IDLT")
            data.idleTimerSetting = GetData<float>();
        else if(subType == "IDLB")
            IgnoreSubRecord();
        else if(subType == "CNAM")
            data.combatStyle = GetData<formid>();
        else level = -1;
    }
    else if(level == 1)
    {
        if(subType == "PKE2")
            data.escortDistance = GetData<uint32_t>();
        else if(subType == "PKFD")
            data.followStartLocationTriggerRadius = GetData<float>();
        else if(subType == "PKPT")
            data.patrolFlags = GetData<uint16_t>();
        else if(subType == "PKW3")
            data.useWeaponData = GetData<DATA::UseWaponData>();
        else if(subType == "PTD2")
            data.target2 = GetData<DATA::Target>();
        else level = -1;
    }
    else if(level == 2)
    {
        if(subType == "PKDD")
            data.dialogData = GetData<DATA::DialogData>();
        else if(subType == "PLD2")
            data.location2 = GetData<DATA::Location>();
        else level = -1; 
    }
    else if(level == 3) // OnBegin
    {
        if(subType == "INAM")
            data.onBeginIdle = GetData<formid>();
        else if(ScriptCollection(&data.onBeginEmbeddedScript)) {}
        else if(subType == "TNAM")
            data.onBeginTopic = GetData<formid>();
        else level = 4;
    }
    else if(level == 4) // OnEnd
    {
        if(subType == "INAM")
            data.onEndIdle = GetData<formid>();
        else if(ScriptCollection(&data.onEndEmbeddedScript)) {}
        else if(subType == "TNAM")
            data.onEndTopic = GetData<formid>();
        else level = 5;
    }
    else if(level == 5) // OnChange
    {
        if(subType == "INAM")
            data.onChangeIdle = GetData<formid>();
        else if(ScriptCollection(&data.onChangeEmbeddedScript)) {}
        else if(subType == "TNAM")
            data.onChangeTopic = GetData<formid>();
        else level = -1;
    }
    else return false;
    return true;
}

