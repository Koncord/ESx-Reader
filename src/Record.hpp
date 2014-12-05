/* 
 * File:   Record.hpp
 * Author: Koncord
 *
 * Created on 18 Ноябрь 2014 г., 15:44
 */

#ifndef RECORD_HPP
#define	RECORD_HPP
#include <vector>
#include <string>
#include <memory>

class SubRecord
{
public:
    virtual void parseData() = 0;
    virtual std::string recordName() {return "";}
};

class Record
{
public:
    struct Header
    {
        uint32_t size;
        uint32_t flags;
        uint32_t formid;
        uint32_t revision;
        uint32_t version; 
    };
protected:
    Header parseHead();

    void RegisterSubRecord(SubRecord* subRec)
    {
        subRecs.emplace_back(subRec);
    }
    void parseSubRecord();
public:
    virtual void parseData() = 0;
    virtual std::string recordName() {return "";}
private:
    std::vector <std::unique_ptr<SubRecord>> subRecs;
};
#endif	/* RECORD_HPP */

