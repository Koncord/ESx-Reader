/* 
 * File:   QUST.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 11 Апрель 2015 г., 21:51
 */

#include "QUST.hpp"


using namespace std;


bool RecordQUST::DoParse()
{
    static int level = 0;
    static CTDA condition;
    const string subType = GetLabel();
    if(subType == "EDID")
    {
        data.edid = GetString();
        level = 0;
    }
    else if(subType == "FULL")
        data.name = GetString();
    else if(subType == "SCRI")
        data.script = GetData<formid>();
    else if(subType == "ICON" || subType == "MICO")
        IgnoreSubRecord();
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>(subhead.dataSize);
    else if(level == 0 && ConditionsData(&condition))
        data.conditions.push_back(condition);
    //-------------------------Stage collection---------------------------------
    else if(subType == "INDX")
    {
        data.stages.push_back(DATA::Stage());
        data.stages.back().stageIndex = GetData<int16_t>();
        data.stages.back().logEntrys.push_back(DATA::Stage::LogEntry());
        level = 1;
    }
    else if(level == 1 && subType == "QSDT")
        data.stages.back().logEntrys.back().stageFlag = GetData<uint8_t>();
    else if(level == 1 && ConditionsData(&condition))
        data.stages.back().logEntrys.back().conditions.push_back(condition);
    else if(level == 1 && subType == "CNAM")
        data.stages.back().logEntrys.back().logEntry = GetString();
    else if(level == 1 && ScriptCollection(&data.stages.back().logEntrys.back().embeddedScript)) {}
    else if(level == 1 && subType == "NAM0")
        data.stages.back().logEntrys.back().nextQuest = GetData<formid>();
    //-------------------------Objective collection-----------------------------
    else if(subType == "QOBJ")
    {
        data.objectives.push_back(DATA::Objective());
        data.objectives.back().objectiveIndex = GetData<uint32_t>();
        level = 2;
    }
    else if(level == 2 && subType == "NNAM")
        data.objectives.back().description = GetString();
    else if(level == 2 && subType == "QSTA")
    {
        data.objectives.back().targets.push_back(DATA::Objective::Target());
        data.objectives.back().targets.back().target = GetData<DATA::Objective::Target::_Target>();
    }
    else if(level == 2 && ConditionsData(&condition))
        data.objectives.back().targets.back().conditions.push_back(condition);
    //--------------------------------------------------------------------------
    else return false;
    return true;
}