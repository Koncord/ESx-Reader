/* 
 * File:   recWEAP.hpp
 * Author: Koncord
 *
 * Created on 18 Ноябрь 2014 г., 19:54
 */

#ifndef RECWEAP_HPP
#define	RECWEAP_HPP

#include "Record.hpp"

class recWEAP: public Record
{
public:
    recWEAP();
    void parseData();
    std::string recordName() {return "WEAP";}
};


#endif	/* RECWEAP_HPP */

