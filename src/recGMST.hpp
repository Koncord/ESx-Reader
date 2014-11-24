/* 
 * File:   recGMST.hpp
 * Author: Koncord
 *
 * Created on 18 Ноябрь 2014 г., 19:07
 */

#ifndef RECGMST_HPP
#define	RECGMST_HPP

#include "Record.hpp"

namespace GMST
{
    struct GMST
    {
        Record::Header head;
        uint32_t id;
        std::string edid;
        std::string data;
    };
    
}

class recGMST: public Record
{
public:
    recGMST();
    virtual void parseData();
    virtual std::string recordName() {return "GMST";}
};

#endif	/* RECGMST_HPP */

