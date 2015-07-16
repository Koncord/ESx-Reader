/* 
 * File:   CPTH.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 20:43
 */

#ifndef CPTH_HPP
#define	CPTH_HPP

#include "../Record.hpp"

class RecordCPTH : public Record
{
public:

    struct DATA
    {
        std::string edid;
        uint8_t cameraZoom;
        enum CameraZoom
        {
            Default = 0,
            Disable = 1,
            ShotList = 2,
        };
        std::vector<CTDA> conditions;
        struct RelatedIdleAnimations
        {
            formid parent;
            formid previousSibling;
        } releatedIdleAnimations;
        std::vector<formid> cameraShot; // FormID of a CAMS record.
    } data;

    explicit RecordCPTH(const RecHeader &head) : Record(head) { Parse(); }

    RecordCPTH() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* CPTH_HPP */

