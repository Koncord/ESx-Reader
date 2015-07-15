/* 
 * File:   ItemCollection.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 10 Апрель 2015 г., 21:37
 */

#include "ItemCollection.hpp"

#include "../Record.hpp"

bool Record::ItemCollection(Items* items)
{
    const std::string subType = GetLabel();
    if(subType == "COED")
    {
        items->back().extra = GetData<Item::COED>(); 
    }
    else if(subType == "CNTO")
    {
        #ifdef DEBUG
            //cerr << "WARNING! SubItemCollection is not fully implemented yet." << endl;
        #endif
        items->push_back(Item());
        items->back().item = GetData<Item::CNTO>();
    }
    else
        return false;
    return true;
}