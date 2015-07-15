/* 
 * File:   DestructionCollection.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 21:32
 */

#include "DestructionCollection.hpp"
#include "../Record.hpp"

bool Record::DestructionData(Destruction *destruction)
{
    const std::string subType = GetLabel();
    static uint32_t damageCounter;
    
    if(subType == "DEST")
    {
        #ifdef DEBUG
            //cerr << "WARNING! DestructionCollection is not fully implemented yet." << endl;
        #endif
        destruction->dest = GetData<Destruction::DEST>();
        destruction->dstages.reserve((uint32_t)destruction->dest.count);
        damageCounter = 0;
    }
    else if (subType == "DSTD")
        destruction->dstages[damageCounter++].dstd = GetData<Destruction::DSTAGE::DSTD>();
    else if(subType == "DMDL" || subType == "DMDT") // skip
        IgnoreSubRecord();
    else if(subType == "DSTF")
        IgnoreSubRecord(); // Destruction Stage End Marker (type = NULL)
    else
        return false;
    return true;
}