/* 
 * File:   PERK.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 8 Апрель 2015 г., 18:35
 */

#include "PERK.hpp"

using namespace std;


bool RecordPERK::DoParse()
{
    static bool subCol_parsing = false;
    CTDA condition;
    string subType = GetLabel();
    if(!subCol_parsing)
    {
        if(subType == "EDID")
            data.edid = GetString();
        else if(subType == "FULL")
            data.name = GetString();
        else if(ModelCollection()) {}
        else if(subType == "MICO" || subType == "ICON") 
            IgnoreSubRecord();
        else if(subType == "DESC")
            data.description = GetString();
        else if(subType == "DATA")
        {
            data.data = GetData<DATA::_DATA>();
        }
        else if(ConditionsData(&condition)) 
                    data.conditions.push_back(condition);
        else if(subType == "PRKE")
        {
            data.effects.push_back(DATA::Effect());
            data.effects.back().header = GetData<DATA::Effect::Header>();
            subCol_parsing = true;
        }
        else return false;
    }
    // ----------------------- Effect Subrecord Collection ---------------------
    else
    {
        if(subType == "DATA")
        {
            if(data.effects.back().header.type == DATA::Effect::Header::Type::QuestAndStage)
                data.effects.back().data = GetData<DATA::Effect::QuestAndStageData>();
            else if(data.effects.back().header.type == DATA::Effect::Header::Type::Ability)
                data.effects.back().data = GetData<formid>();
            else if(data.effects.back().header.type == DATA::Effect::Header::Type::EntryPoint)
                data.effects.back().data = GetData<DATA::Effect::EntryPointData>();
        }
        else if(subType == "PRKC")
            data.effects.back().condtitionColl.runOn = GetData<uint8_t>();
        else if(subType == "CTDA")
            data.effects.back().condtitionColl.conditions.push_back(GetData<CTDA>());
        else if(subType == "EPFT")
            data.effects.back().entryPointFunctionType = GetData<uint8_t>();
        else if(subType == "EPFD")
        {
            TODO(Check this code)
            switch(data.effects.back().entryPointFunctionType)
            {
            case 0:
                data.effects.back().entryPointFunctionData = GetRawData(); break;
            case 1:
                data.effects.back().entryPointFunctionData = GetData<float>(); break;
            case 2:
                data.effects.back().entryPointFunctionData = GetData<DATA::Effect::EPFD_2>(); break;
            case 3:
                data.effects.back().entryPointFunctionData = GetData<formid>(); break;
            case 4:
                break;
            case 5:
                data.effects.back().entryPointFunctionData = GetData<DATA::Effect::EPFD_5>(); break;
            }
        }
        else if(subType == "EPF2")
            data.effects.back().buttonLabel = GetString();
        else if(subType == "EPF3")
            data.effects.back().scriptFlags = GetData<uint16_t>();
        else if(ScriptCollection(&data.effects.back().script)) { }
        else if(subType == "PRKF")
            subCol_parsing = false;
        else return false;
    }
    //--------------------------------------------------------------------------
    return true;
}
