/* 
 * File:   recGMST.cpp
 * Author: Koncord
 * 
 * Created on 18 Ноябрь 2014 г., 19:07
 */

#include "recGMST.hpp"
#include "Reader.hpp"

using namespace std;

static GMST::GMST gmst;
static Reader *esm = nullptr;

namespace GMST
{
    class recEDID: public SubRecord
    {
        public:
        void parseData()
        {

            uint16_t size;
            esm->get(&size);
            
            char *str = new char[size];
            esm->get(str, size);
            gmst.edid = str;
            delete[] str;
        }
        std::string recordName() {return "EDID";} 
    };
    
    class recDATA: public SubRecord
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
            if(gmst.edid[0] == 's')
            {
                char *data = new char[size];
                esm->get(data, size);
                gmst.data = data;
                delete[] data;
            }
            else if(gmst.edid[0] == 'f')
            {
                float data;
                esm->get(&data);
                gmst.data = data;
            }
            else if(gmst.edid[0] == 'i')
            {
                int data;
                esm->get(&data);
                gmst.data = data;
            }
        }
        std::string recordName() {return "DATA";} 
    };
}

recGMST::recGMST()
{
    esm = Reader::getSingletonPtr();
    
    RegisterSubRecord(new GMST::recEDID);
    RegisterSubRecord(new GMST::recDATA);
}

void recGMST::parseData()
{
    gmst.head = parseHead();
    
    parseSubRecord();
    
    esm->settings.emplace_back(new GMST::GMST(gmst));
}