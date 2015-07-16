/* 
 * File:   DOBJ.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 21:17
 */

#ifndef DOBJ_HPP
#define	DOBJ_HPP

#include "../Record.hpp"
class RecordDOBJ : public Record
{
    private:
        int obj_counter;
public:

    struct DATA
    {
        std::string edid;
        formid defaultObject[21];
        struct DefaultObjects
        {
            formid stimpack;
            formid superStimpack;
            formid radX;
            formid radAway;
            formid morphine;
            formid perkParalysis;
            formid playerFaction;
            formid mysteriousStrangerNPC;
            formid mysteriousStrangerFaction;
            formid defaultMusic;
            formid battleMusic;
            formid deathMusic;
            formid successMusic;
            formid levelUpMusic;
            formid playerVoiceMale;
            formid playerVoiceMaleChild;
            formid playerVoiceFemale;
            formid playerVoiceFemaleChild;
            formid eatPackageDefaultFood;
            formid everyActorAbility;
            formid DrugWearsOffImageSpace;
        } defaultObjects;
    } data;

    explicit RecordDOBJ(const RecHeader &head) : Record(head), obj_counter(0) { Parse(); }

    RecordDOBJ() : Record(), obj_counter(0) { Parse(); }
    virtual bool DoParse();
};


#endif	/* DOBJ_HPP */

