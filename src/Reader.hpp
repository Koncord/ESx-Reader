/* 
 * File:   Reader.hpp
 * Author: Koncord
 *
 * Created on 25 Август 2014 г., 19:20
 */

#ifndef READER_HPP
#define	READER_HPP
#include<Singleton.hpp>
#include "Record.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include "recWEAP.hpp"
#include "recGMST.hpp"
struct Data
{
    std::string Name;
    std::string Author;
    std::string Description;
    uint32_t records;
    std::vector<std::string> masters;
};


class Reader: public rwa::Singleton<Reader>
{
public:
    Reader(std::string);
    std::string getRecName();
    template<class T>
    bool get(T *x, int size)
    {
        if(esm.eof()) return 0;
        esm.read((char*)x, size);
        return 1;
    }
    void setPos(std::streampos ss) {esm.seekg(ss);}
    std::streampos getPos() { return esm.tellg();}
    void ignoreBytes(std::streamsize ss){esm.ignore(ss);}
    virtual ~Reader();
    Data data;
    std::vector<std::unique_ptr<Record>> records;
    std::vector<std::unique_ptr<WEAP::Weap>> weapons;
    std::vector<std::unique_ptr<GMST::GMST>> settings;
private:
    std::ifstream esm;
    
};

#endif	/* READER_HPP */

