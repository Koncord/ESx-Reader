/* 
 * File:   Reader.cpp
 * Author: Koncord
 * 
 * Created on 25 Август 2014 г., 19:20
 */


#ifdef _DEBUG_
#include <iostream>
#else
#include <stdexcept>
#endif

#include <stdint.h>

#include <sstream>
#include "Reader.hpp"
#include "recTES4.hpp"
#include "recWEAP.hpp"
using namespace std;

template<> Reader* rwa::Singleton<Reader>::msSingleton = 0;


class recGRUP: public Record
{
public:
    recGRUP()
    {
        
    }
    void parseData()
    {
        Reader *esm = Reader::getSingletonPtr();
        esm->get(&size, 4);
        size -=4;
        
        string groupname = esm->getRecName();
        #ifdef _DEBUG_
            cout << "groupname: " << groupname << endl;
        #endif
        size -=4;
        
        esm->get(&flag1, 4);
        esm->get(&flag2, 4);
        esm->get(&flag3, 4);
        size -= 12;
        
        if(groupname == "ARMO")
        {
            string record(esm->getRecName());
            size -= 4;
            #ifdef _DEBUG_
                cout << "record: " << record << endl;
            #endif
            
        }
        if(groupname == "WEAP")
        {
            string record(esm->getRecName());
            size -= 4;
            #ifdef _DEBUG_
                cout << "record: " << record << endl;
            #endif
            recWEAP *recw = new recWEAP;
            recw->parseData();
            
        }

        esm->ignoreBytes(size - 4);
        
    }
    std::string recordName() {return "GRUP";}
    vector <Record*> records;
    uint32_t size;
    uint32_t flag1, flag2, flag3;
};

Reader::Reader(std::string file)
{
    
    esm.open(file, ifstream::binary);
    records.emplace_back(make_unique<recTES4>());
    records.emplace_back(make_unique<recGRUP>());
    
    bool t = true;
    while(t)
    {
        if(esm.eof()) break;
        string recName(getRecName());
        
        t = false;
        for(auto &record : records)
        {
            if(record->recordName() == recName)
            {
                record->parseData();
                t = true;
                break;
            }
        }
        
        
        if(t == false && esm.tellg() != -1)
        {
            stringstream sstr;
            sstr << "unkown record: \""<< recName << "\" on position: " << esm.tellg() << endl;
            #ifndef _DEBUG_
                throw runtime_error(sstr.str());
            #else
                cout << sstr.str();
            #endif
        }
    }
    
    #ifdef _DEBUG_
        cout << endl << "Author: " << data.Author << endl << "Description: " << data.Description << endl;
        cout << endl << "master files: " << endl;
        for(auto &master : data.masters)
        {
            cout<<master << + " ";
        }
        cout << endl;
    #endif
}

Reader::~Reader()
{
    esm.close();
}

string Reader::getRecName()
{
    if(esm.eof()) return "";
    char buf[5] = {0};
    esm.read(buf, 4);
    return buf;
}