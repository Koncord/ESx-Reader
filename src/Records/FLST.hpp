/* 
 * File:   FLST.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 5 Февраль 2015 г., 16:25
 */

#ifndef FLST_HPP
#define	FLST_HPP

#include "../Record.hpp"

class RecordFLST : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::vector<formid> formids;
    } data;

    explicit RecordFLST(const RecHeader &head) : Record(head) { Parse(); }

    RecordFLST() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* FLST_HPP */
