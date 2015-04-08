/* 
 * File:   ANIO.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 22:23
 */

#ifndef ANIO_HPP
#define	ANIO_HPP

#include "../Record.hpp"

class RecordANIO : public Record
{
public:

    struct DATA
    {
        std::string edid;
        formid animation; // FormID of an IDLE record.
    } data;

    explicit RecordANIO(const RecHeader &head) : Record(head) { Parse(); }

    RecordANIO() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* ANIO_HPP */

