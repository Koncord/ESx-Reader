/* 
 * File:   Reader.cpp
 * Author: Koncord
 * 
 * Created on 25 Август 2014 г., 19:20
 */

#include "recCELL.hpp"



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
#include "recGMST.hpp"
#include "recCELL.hpp"

using namespace std;

template<> Reader* rwa::Singleton<Reader>::msSingleton = 0;

namespace GRUP
{
    struct Header
    {
        uint32_t size;
        char label[4];
        uint32_t groupType;
        uint32_t stamp; 
        uint32_t version;
    };
}

class recGRUP: public Record
{
public:
    recGRUP()
    {
        esm = Reader::getSingletonPtr();
        records.emplace_back(make_unique<recWEAP>());
        records.emplace_back(make_unique<recGMST>());
        records.emplace_back(make_unique<recCELL>());
    }
    void parseData()
    {
        
        long long readed = esm->getPos();
        
        esm->get(&grup, 20);
        
        string groupname = grup.label;
        #ifdef _DEBUG_
            cout << "groupname: " << groupname << endl;
        #endif
        
        for (auto &rec : records)
        {
            if(groupname == rec->recordName())
            {
                while(true)
                {
                    string record(esm->getRecName());
                    if(record == recordName()) // TODO: I do not know how to do it better. Maybe this not needed in vaultmp
                    {
                        GRUP::Header subgroup;
                        esm->get(&subgroup, 20);
                        continue;
                    }
                    #ifdef _DEBUG_
                    if(record.size() > 0)
                        cout << "record: " << record << endl;
                    #endif
                    if(record != rec->recordName())
                    {
                        esm->setPos(esm->getPos() - 4ll);
                        break;
                    }
                    rec->parseData();
                }
                break;
            }
        }
            
        esm->ignoreBytes(grup.size - (esm->getPos() - readed) - 4);
    }
    
    std::string recordName() {return "GRUP";}
private:
        vector <unique_ptr<Record>> records;
        Reader *esm;
        GRUP::Header grup;
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