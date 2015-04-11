/* 
 * File:   SCPT.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 4 Февраль 2015 г., 18:22
 */

#ifndef SCPT_HPP
#define	SCPT_HPP

#include "../Record.hpp"

class RecordSCPT : public Record
{
public:

    struct DATA
    {
        std::string edid;
        Script script;
    } data;

    explicit RecordSCPT(const RecHeader &head) : Record(head) { Parse(); }

    RecordSCPT() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* SCPT_HPP */

