/* 
 * File:   Reader.cpp
 * Author: Koncord
 * 
 * Created on 25 Август 2014 г., 19:20
 */

#include <stdexcept>
#include <iostream>
#include <stdint.h>
#include <vector>

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
        cout << "groupname: " << groupname << endl;
        size -=4;
        
        esm->get(&flag1, 4);
        esm->get(&flag2, 4);
        esm->get(&flag3, 4);
        size -= 12;
        
        if(groupname == "ARMO")
        {
            string record(esm->getRecName());
            size -= 4;
            cout << "record: " << record << endl;
            
        }
        if(groupname == "WEAP")
        {
            string record(esm->getRecName());
            size -= 4;
            cout << "record: " << record << endl;
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
    
    records.push_back(new recTES4);
    records.push_back(new recGRUP);
    
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
        
        if(t == false)
        {
            stringstream sstr;
            sstr << "unkown record: \""<< recName << "\" on position: 0x" << esm.tellg() << endl;
            //throw runtime_error(sstr.str());
            cout << sstr.str();
        }
    }
    
    
    cout << endl << "Author: " << data.Author << endl << "Description: " << data.Description << endl;
    cout << endl << "master files: " << endl;
    for(auto &master : data.masters)
    {
        cout<<master << + " ";
    }
    cout << endl;
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