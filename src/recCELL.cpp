/* 
 * File:   CELL.cpp
 * Author: Koncord
 * 
 * Created on 5 Декабрь 2014 г., 13:06
 */

#include "recCELL.hpp"
#include "Reader.hpp"

#ifdef _DEBUG_
#include <iostream>
#endif

using namespace std;

static Reader *esm = nullptr;
static CELL::CELL cell;

namespace CELL
{
    class recEDID: public SubRecord
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
            char *edid = new char[size];
            esm->get(edid, size);
            cell.edid = edid;
            delete[] edid;
        }
        std::string recordName() {return "EDID";}
    };

    class recFULL: public SubRecord // ingame name
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            
            char *full = new char[size];
            esm->get(full, size);
            cell.full = full;
            delete[] full;
        }
        std::string recordName() {return "FULL";}
    };
    class recDATA: public SubRecord // flags
    {
        public:
        void parseData()
        {
            uint16_t size;
            esm->get(&size);
            esm->get(&cell.DATA);
        }
        std::string recordName() {return "DATA";}
    };
}

recCELL::recCELL()
{
    esm = Reader::getSingletonPtr();
    RegisterSubRecord(new CELL::recEDID);
    RegisterSubRecord(new CELL::recFULL);
    RegisterSubRecord(new CELL::recDATA);
}

void recCELL::parseData()
{
    cell.head = parseHead();
    parseSubRecord();
    //esm->cell.emplace_back(new CELL::CELL(cell));
    #ifdef _DEBUG_DETAIL
        cout << "FORMID: 0x"<< hex << uppercase <<  cell.head.formid
             << " EDID: " << cell.edid
             << " FULL: " << cell.full << endl
             << "\tFlags:" << endl
             << "isInterior: " <<cell.DATA.isInterior() << endl
             << "Has Watter: " <<cell.DATA.HasWatter() << endl
             << "Can't travel: " <<cell.DATA.CantTravel() << endl
             << "Public area: " <<cell.DATA.PublicArea() << endl
             << "Hand changed: " <<cell.DATA.HandChanged() << endl;
    #endif // _DEBUG_DETAIL
}