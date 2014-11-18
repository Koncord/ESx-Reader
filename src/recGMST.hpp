/* 
 * File:   recGMST.hpp
 * Author: Koncord
 *
 * Created on 18 Ноябрь 2014 г., 19:07
 */

#ifndef RECGMST_HPP
#define	RECGMST_HPP

#include "Record.hpp"

class recGMST: public Record
{
public:
    recGMST();
    virtual void parseData();
    virtual std::string recordName() {return "GMST";}
};

#endif	/* RECGMST_HPP */

