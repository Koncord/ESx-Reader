/* 
 * File:   recTES4.cpp
 * Author: Koncord
 * 
 * Created on 18 Ноябрь 2014 г., 18:11
 */

#include "recTES4.hpp"
#include "Reader.hpp"

using namespace std;

class recHEDR: public SubRecord
{
    public:
    void parseData()
    {
        Reader *esm = Reader::getSingletonPtr();

        uint16_t size;
        esm->get(&size);
        
        esm->ignoreBytes(4); // version (float)
        esm->get(&esm->data.records); // Record count
        esm->ignoreBytes(4); // nextObjId (int)
        
    }
    std::string recordName() {return "HEDR";}
};

class recCNAM : public SubRecord
{
    public:
        void parseData()
        {
            Reader *esm = Reader::getSingletonPtr();

            uint16_t size;
            esm->get(&size);

            char *text = new char[size];
            esm->get(text, size);
            esm->data.Author = text;
            delete[] text;
        }
        string recordName() {return "CNAM";}
};

class recSNAM: public SubRecord
{
    public:
    void parseData()
    {
        Reader *esm = Reader::getSingletonPtr();

        uint16_t size;
        esm->get(&size);
        
        char *text = new char[size];
        esm->get(text, size);
        esm->data.Description = text;
        delete[] text;
    }
    std::string recordName() {return "SNAM";}
};

class recMAST: public SubRecord
{
    public:
    void parseData()
    {
        Reader *esm = Reader::getSingletonPtr();

        uint16_t size;
        esm->get(&size);
        
        char *text = new char[size];
        esm->get(text, size);
        esm->data.masters.push_back(text);
        delete[] text;
        
    }
    std::string recordName() {return "MAST";}
};

class recDATA: public SubRecord
{
    public:
    void parseData()
    {
        Reader *esm = Reader::getSingletonPtr();

        uint16_t size;
        esm->get(&size);
        
        esm->ignoreBytes(size);
    }
    std::string recordName() {return "DATA";}
};

class recONAM: public SubRecord // TODO: stub
{
    public:
    void parseData()
    {
        Reader *esm = Reader::getSingletonPtr();

        uint16_t size;
        esm->get(&size);
        
        esm->ignoreBytes(size);
    }
    std::string recordName() {return "ONAM";}
};


recTES4::recTES4()
{
    RegisterSubRecord(new recHEDR);
    RegisterSubRecord(new recCNAM);
    RegisterSubRecord(new recSNAM);
    RegisterSubRecord(new recMAST);
    RegisterSubRecord(new recDATA);
    RegisterSubRecord(new recONAM);
}

void recTES4::parseData()
{
    Reader *esm = Reader::getSingletonPtr();
    esm->ignoreBytes(20);
    
    parseSubRecord();
}