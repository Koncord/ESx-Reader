/* 
 * File:   recGLOB.hpp
 * Author: Koncord
 *
 * Created on 5 Декабрь 2014 г., 17:16
 */

#ifndef RECGLOB_HPP
#define	RECGLOB_HPP

#include "Record.hpp"

namespace GLOB
{
    struct GLOB
    {
        Record::Header head;
        std::string edid;
        char fnam;
        float fltv;
    };
}

class recGLOB: public Record
{
public:
    recGLOB();
    void parseData();
    std::string recordName() {return "CELL";}
};

#endif	/* RECGLOB_HPP */

