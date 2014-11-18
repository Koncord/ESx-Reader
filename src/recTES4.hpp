/* 
 * File:   recTES4.hpp
 * Author: Koncord
 *
 * Created on 18 Ноябрь 2014 г., 18:11
 */

#ifndef RECTES4_HPP
#define	RECTES4_HPP
#include "Record.hpp"
#include <string>


class recTES4: public Record
{
    public:
    recTES4();
    void parseData();
    std::string recordName() {return "TES4";}
};

#endif	/* RECTES4_HPP */

