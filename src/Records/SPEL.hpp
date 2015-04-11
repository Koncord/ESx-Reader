/* 
 * File:   SPEL.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 0:37
 */

#ifndef SPEL_HPP
#define	SPEL_HPP

#include "../Record.hpp"
class RecordSPEL : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        std::vector<Effect> effects;
        #pragma pack(push, 1)
        struct _DATA
        {
            uint32_t type;
            uint32_t cost; // unused
            uint32_t level; // unused
            uint8_t flags; // unused
            int8_t unused[3];
            
            enum Type
            {
                ActorEffect = 0,
                Disease = 1,
                Power,
                LesserPower,
                Ability,
                Poison,
                Unknown0,
                Unknown1,
                Unknown2,
                Unknown3,
                Addiction
            };
            enum FLAGS
            {
                NoAutoCalc = 0x01,
                ImmuneToSilence1 = 0x02, // ?
                PCStartEffect = 0x04,
                ImmuneToSilence2 = 0x08, // ?
                AreaEffectIgnoresLOS = 0x10,
                ScriptEffectAlwaysApplies = 0x20,
                DisableAbsorb = 0x40,
                Reflect = 0x40,
                ForceTouchExplode = 0x80
            };
        } data;
        #pragma pack(pop)
    } data;

    explicit RecordSPEL(const RecHeader &head) : Record(head) { Parse(); }

    RecordSPEL() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* SPEL_HPP */

