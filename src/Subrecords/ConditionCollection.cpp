/* 
 * File:   ConditionCollection.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 21:16
 */

#include "ConditionCollection.hpp"
#include "../Record.hpp"

bool Record::ConditionsData(CTDA* cond)
{
    const std::string subType = GetLabel();
    if(subType == "CTDA")
    {
        #ifdef DEBUG
            //cerr << "WARNING! CTDA is not fully implemented yet." << endl;
        #endif
        (*cond) = GetData<CTDA>(); 
    }
    else
        return false;
    return true;
}