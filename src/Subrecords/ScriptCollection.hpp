/* 
 * File:   ScriptCollection.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 10 Апрель 2015 г., 21:24
 */

#ifndef SCRIPTCOLLECTION_HPP
#define	SCRIPTCOLLECTION_HPP
#include "../Types.hpp"
#include "../debug_macros.hpp"

#pragma pack(push, 1)
struct Script
{
    todo(rename structures)
    std::vector<uint8_t> compiled;
    std::string source;
    std::vector<formid> globRefs; // ACTI, DOOR, STAT, FURN, CREA, SPEL, NPC_, CONT, ARMO,
                                   // AMMO, MISC, WEAP, IMAD, BOOK, KEYM, ALCH, LIGH, QUST, PLYR,
                                   // PACK, LVLI, ECZN, EXPL, FLST, IDLM, PMIS, FACT, ACHR, REFR, ACRE,
                                   // GLOB, DIAL, CELL, SOUN, MGEF, WTHR, CLAS, EFSH, RACE, LVLC, CSTY,
                                   // WRLD, SCPT, IMGS, MESG, MSTT, MUSC, NOTE, PERK, PGRE, PROJ, LVLN,
                                   // WATR, ENCH, TREE, TERM, HAIR, EYES, ADDN or NULL record.
    std::vector<uint32_t> locRefs;
    struct LocalVariable
    {
        struct SLSD
        {
            uint32_t index;
            uint8_t unused[12];
            bool isLongOrShort;
            uint8_t unused1[7];
        }data;

        std::string name;
    };
    std::vector<LocalVariable> localVariables;
    struct SCHR
    {
        uint8_t unused[4];
        uint32_t refCount;
        uint32_t compiledSize;
        uint32_t variableCount;
        uint16_t type;
        bool enabled;
        uint8_t unused1;
    } main;
    enum TYPE
    {
        Object = 0,
        Quest,
        Effect = 0x100
    };
};
#pragma pack(pop)

typedef std::vector<Script> Scripts;

#endif	/* SCRIPTCOLLECTION_HPP */

