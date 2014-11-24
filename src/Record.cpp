/* 
 * File:   Record.cpp
 * Author: Koncord
 * 
 * Created on 18 Ноябрь 2014 г., 15:44
 */

#include "Record.hpp"
#include "Reader.hpp"
#ifdef _DEBUG_
#include <iostream>
#endif

using namespace std;

Record::Header Record::parseHead()
{
    Reader *esm = Reader::getSingletonPtr();
    Record::Header head;
    
    esm->get(&head, 20);
    
    return head;
}

void Record::parseSubRecord()
{
    bool t;
    string recName;
    Reader *esm = Reader::getSingletonPtr();
    do
    {
        t = false;
        recName = esm->getRecName();
        
        if(recName == "" || recName == recordName() || recName == "GRUP") break;
        
        #ifdef _DEBUG_DETAIL
            cout << "SubRecord: " << recName;
        #endif
        for(auto &subRec : subRecs)
        {
            if(subRec->recordName() == recName)
            {
                subRec->parseData();
                t = true;
                break;
            }
        }
        
        if(!t)
        {
            uint16_t size;
            esm->get(&size, 2);
            esm->ignoreBytes(size);
            t = true;
            #ifdef _DEBUG_DETAIL
                cout << " skipping...";
            #endif
        }
        
        #ifdef _DEBUG_DETAIL
        cout << endl;
        #endif
        
    }
    while(t);
    
    
    esm->setPos(esm->getPos() - 4ll); // super crutch
}
