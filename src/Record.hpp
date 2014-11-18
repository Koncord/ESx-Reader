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

class SubRecord
{
    public:
    virtual void parseData() = 0;
    virtual std::string recordName() {return "";}
};

class Record
{
protected:
    void RegisterSubRecord(SubRecord* subRec)
    {
        subRecs.push_back(subRec);
    }
    void parseSubRecord();
public:
    virtual void parseData() = 0;
    virtual std::string recordName() {return "";}
private:
    std::vector <SubRecord*> subRecs;
};
#endif	/* RECORD_HPP */

