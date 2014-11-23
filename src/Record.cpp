/* 
 * File:   Record.cpp
 * Author: Koncord
 * 
 * Created on 18 Ноябрь 2014 г., 15:44
 */

#include "Record.hpp"
#include "Reader.hpp"
#include <iostream>
using namespace std;
void Record::parseSubRecord()
{
    bool t;
    string recName;
    Reader *esm = Reader::getSingletonPtr();
    do
    {
        t = false;
        recName = esm->getRecName();
        if(recName == "") break;
        cout << "SubRecord: " << recName;
        for(auto &subRec : subRecs)
        {
            if(subRec->recordName() == recName)
            {
                subRec->parseData();
                t = true;
                break;
            }
        }
        if(recName != "" && recName != "GRUP")
        if(t == false)
        {
            uint16_t size;
            esm->get(&size, 2);
            cout << " skipping...";
            esm->ignoreBytes(size);
            t = true;
        }
        cout << endl;
        
    }
    while(t);
    
    
    esm->setPos(esm->getPos() - 4ll); // super crutch
}

