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
        enum ObjectMap
        {
            Stimpack = 0,
            SuperStimpack,
            RadX,
            RadAway,
            Morphine,
            PerkParalysis,
            PlayerFaction,
            MysteriousStrangerNPC,
            MysteriousStrangerFaction,
            DefaultMusic,
            BattleMusic,
            DeathMusic,
            SuccessMusic,
            PlayerVoiceMale,
            PlayerVoiceMaleChild,
            PlayerVoiceFemale,
            PlayerVoiceFemaleChild,
            EatPackageDefaultFood,
            EveryActorAbility,
            DrugWearsOffImageSpace
        };
    } data;

    explicit RecordDOBJ(const RecHeader &head) : Record(head), obj_counter(0) { Parse(); }

    RecordDOBJ() : Record(), obj_counter(0) { Parse(); }
    virtual bool DoParse();
};


#endif	/* DOBJ_HPP */

