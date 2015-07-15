/* 
 * File:   ScriptCollection.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 21:24
 */

#include "ScriptCollection.hpp"
#include "../Record.hpp"
bool Record::ScriptCollection(Script* scr)
{
    const std::string subType = GetLabel();
    if(subType == "SCHR")
        scr->main = GetData<Script::SCHR>();
    else if(subType == "SCDA")
    {
        scr->compiled.reserve(subhead.dataSize);
        for(int i = 0; i < subhead.dataSize; i++)
        {
            scr->compiled.push_back(GetData<uint8_t>());
        }
    }
    else if(subType == "SCTX")
        scr->source = GetString();
    else if(subType == "SCRO")
        scr->globRefs.push_back(GetData<formid>());
    else if(subType == "SLSD")
    {
        scr->localVariables.push_back(Script::LocalVariable());
        scr->localVariables.back().data = GetData<Script::LocalVariable::SLSD>();
    }
    else if(subType == "SCVR")
    {
        scr->localVariables.back().name = GetString();
    }
    else if(subType == "SCRV")
    {
        scr->locRefs.push_back(GetData<uint32_t>());
    }
    else return false;
    return true;
}