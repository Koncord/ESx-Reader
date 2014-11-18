/* 
 * File:   recGMST.cpp
 * Author: Koncord
 * 
 * Created on 18 Ноябрь 2014 г., 19:07
 */

#include "recGMST.hpp"
#include "Reader.hpp"

class recEDID: public SubRecord
{
    public:
    void parseData()
    {
        Reader *esm = Reader::getSingletonPtr();

        uint16_t size;
        esm->get(&size, 2);
        
        esm->ignoreBytes(size);
    }
    std::string recordName() {return "EDID";}
};

recGMST::recGMST()
{
    RegisterSubRecord(new recEDID);
}

void recGMST::parseData()
{
    Reader *esm = Reader::getSingletonPtr();
    esm->ignoreBytes(20);
    
    parseSubRecord();
}