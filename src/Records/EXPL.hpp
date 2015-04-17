/* 
 * File:   EXPL.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 6 Февраль 2015 г., 0:33
 */

#ifndef EXPL_HPP
#define	EXPL_HPP

#include "../Record.hpp"

class RecordEXPL : public Record
{
public:

    struct DATA
    {
        std::string edid;
        std::string name;
        formid objectEffectId; // ENCH or SPEL record.
        formid placedImpactObject; // TREE, SOUN, ACTI, DOOR, STAT, FURN, CONT, 
                                   // ARMO, AMMO, LVLN, LVLC, MISC, WEAP, BOOK,
                                   // KEYM, ALCH, LIGH, GRAS, ASPC, IDLM, ARMA,
                                   //MSTT, NOTE, PWAT, SCOL, TACT, TERM or TXST record.
        ObjectBounds objectBounds;
        #pragma pack(push, 1)
        struct _DATA
        {
          float force;
          float damage;
          float radius;
          formid light; // LIGH record, or null.
          formid sound1; // SOUN record, or null.
          uint32_t flags;
          float ISRadius;
          formid impactData; // IPDS record, or null.
          formid sound2; // SOUN record, or null.
          float radiationLevel;
          float radiationDissipationTime;
          float radiationRadius;
          uint32_t sndLevel;
        } data;
        #pragma pack(pop)
    } data;

    explicit RecordEXPL(const RecHeader &head) : Record(head) { Parse(); }

    RecordEXPL() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* EXPL_HPP */

