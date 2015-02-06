/* 
 * File:   GLOB.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 31 Январь 2015 г., 23:58
 */

#ifndef GLOB_HPP
#define	GLOB_HPP

#include "../Group.hpp"
#include "../Record.hpp"

class RecordGLOB : public Record
{
public:

    struct DATA
    {
        std::string edid;
        uint8_t type;
        float value;

        enum DataType
        {
            Float = 'f',
            Long = 'l',
            Short = 's'
        };
    } data;

    explicit RecordGLOB(const RecHeader &head) : Record(head) { Parse(); }

    RecordGLOB() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* GLOB_HPP */
