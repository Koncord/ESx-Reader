/* 
 * File:   LIGH.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 15:05
 */

#ifndef LIGH_HPP
#define	LIGH_HPP

#include "../Record.hpp"
class RecordLIGH : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        ObjectBounds objectBounds;
        formid script;
        float fadeValue;
        formid sound;
        #pragma pack(push, 1)
        struct _DATA
        {
            int32_t time;
            uint32_t radius;
            rgba color;
            uint32_t flags;
            float falloffExponent;
            float FOV;
            uint32_t value;
            float weight;
            enum Flags
            {
                Dynamic = 0x00000001,
                CanBeCarried = 0x00000002,
                Negative = 0x00000004,
                Flicker = 0x00000008,
                Unused = 0x00000010,
                OffByDefault = 0x00000020,
                FlickerSlow = 0x00000040,
                Pulse = 0x00000080,
                PulseSlow = 0x00000100,
                SpotLight = 0x00000200,
                SpotShadow = 0x00000400
            };
        } data;
        #pragma pack(pop)
    } data;

    explicit RecordLIGH(const RecHeader &head) : Record(head) { Parse(); }

    RecordLIGH() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* LIGH_HPP */

