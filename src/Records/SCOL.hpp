/* 
 * File:   SCOL.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 15:15
 */

#ifndef SCOL_HPP
#define	SCOL_HPP

#include "../Record.hpp"

class RecordSCOL : public Record
{
public:

    struct DATA
    {
        std::string edid;
        OBND objectBounds;
        
        #pragma pack(push, 1)
        struct Part
        {
            formid _static; // FormID of a STAT record.
            struct Placement
            {
                float posX, posY, posZ;
                float rotX, rotY, rotZ;
                float scale;
            } placement;
        };
        std::vector<Part> parts;
        #pragma pack(pop)
    } data;

    explicit RecordSCOL(const RecHeader &head) : Record(head) { Parse(); }

    RecordSCOL() : Record() { Parse(); }
    virtual bool DoParse();
};


#endif	/* SCOL_HPP */

