/* 
 * File:   TERM.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 1 Февраль 2015 г., 14:27
 */

#ifndef TERM_HPP
#define	TERM_HPP

#include "../Record.hpp"
#include <vector>

class RecordTERM : public Record
{
public:
    struct DATA
    {
        std::string edid;
        std::string name;
        std::string description;
        formid scriptId;
        formid passwordNoteId;
        Destruction destruction;
        OBND objectBounds;
        #pragma pack(push, 1)
        struct DNAM
        {
            uint8_t baseHackDifficulty;
            uint8_t flags;
            uint8_t serverType;
            uint8_t unused[1];
            enum DIFFICULTY
            {
                VeryEasy = 0,
                Easy,
                Average,
                Hard,
                VeryHard,
                RequiresKey
            };
            enum FLAG
            {
                Leveled = 0x01,
                Unlocked = 0x02,
                AlternateColors = 0x04,
                HideWelcomeTextWhenDisplayingText = 0x08
            };
            enum ServerType
            {
                Server1 = 0,
                Server2,
                Server3,
                Server4,
                Server5,
                Server6,
                Server7,
                Server8,
                Server9
            };
        } dnam;
        #pragma pack(pop)
        struct MENUITM
        {
            std::string itemText;
            std::string resultText;
            uint8_t flags;
            formid displayNoteId; // NOTE record.
            formid subMenuId; // TERM record.
            Script script;
            CTDA conditions;
        };
        std::vector<MENUITM> items;
    } data;
    explicit RecordTERM(const RecHeader &head) : Record(head){Parse(); }
    RecordTERM() : Record() {Parse();}
    virtual bool DoParse();
};


#endif	/* TERM_HPP */
