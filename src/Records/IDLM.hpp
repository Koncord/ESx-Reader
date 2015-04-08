/* 
 * File:   IDLM.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 8 Апрель 2015 г., 22:03
 */

#ifndef IDLM_HPP
#define	IDLM_HPP

#include "../Record.hpp"

class RecordIDLM : public Record
{
public:

    struct DATA
    {
        std::string edid;
        uint8_t flags;
        enum Flag
        {
            RunInSequence = 0x01,
            Unknown = 0x02,
            DoOnce = 0x04
        };
        uint32_t animationCount;
        float idleTimerSetting;
        std::vector<formid> animation; // FormID of a IDLE record, or null.
        #pragma pack(push, 1)
        struct OBND 
        {
            uint16_t x1, y1, z1;
            uint16_t x2, y2, z2;
        } obnd;
        #pragma pack(pop)
    } data;

    explicit RecordIDLM(const RecHeader &head) : Record(head) { Parse(); }

    RecordIDLM() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* IDLM_HPP */

