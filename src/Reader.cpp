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
#include <memory>
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
        records.emplace_back(make_unique<recWEAP>());
    }
    void parseData()
    {
        Reader *esm = Reader::getSingletonPtr();
        long long readed = esm->getPos();
        uint32_t size;
        esm->get(&size, 4);
        
        string groupname = esm->getRecName();
        #ifdef _DEBUG_
            cout << "groupname: " << groupname << endl;
        #endif
        
        esm->get(&groupType, 4);
        esm->get(&flag2, 4);
        esm->get(&flag3, 4);
        
        for (auto &rec : records)
        {
            if(groupname == rec->recordName())
            {
                while(true)
                {
                    string record(esm->getRecName());
                    if(record != rec->recordName())
                    {
                        esm->setPos(esm->getPos() - 4ll);
                        break;
                    }
                    #ifdef _DEBUG_
                         cout << " record: " << record << endl;
                    #endif
                    rec->parseData();
                }
                break;
            }
        }

        size -= esm->getPos() - readed;
        esm->ignoreBytes(size - 4);
    }
    
    std::string recordName() {return "GRUP";}

    uint32_t groupType, flag2, flag3;
private:
        vector <unique_ptr<Record>> records;
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
        
        
        if(!t && esm.tellg() != -1)
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
        if(data.masters.size() > 0)
        {
            cout << endl << "master files: " << endl;
            for(auto &master : data.masters)
            {
                cout<<master << + " ";
            }
            cout << endl;
        }
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