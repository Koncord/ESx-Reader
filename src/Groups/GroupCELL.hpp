/* 
 * File:   CELL.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 29 Май 2015 г., 6:42
 */

#ifndef GCELL_HPP
#define	GCELL_HPP

#include "../Record.hpp"
#include "../Records/CELL.hpp"
#include "../Records/REFR.hpp"

class GroupCELL
{
public:

    struct DATA
    {
        RecordCELL::DATA cell;

        struct Persistent
        {
            /*IDHash<RecordACRE::DATA> placedCreatures;
            IDHash<RecordACHR::DATA> placedNPCs;*/
            IDHash<RecordREFR::DATA> placedObjects;
            /*IDHash<RecordPGRE::DATA> placedGrenades;
            IDHash<RecordPMIS::DATA> placedMissiles;*/
        } persistent;
        using Temporary = Persistent;
        Temporary temporary;
    };

    class Helper
    {
    public:
        Helper(MapHash<DATA> *cellCols);
        void insert(Block block, IDHash<DATA> cells);
        IDHash<DATA> get(Block block) const;
        DATA get(Block block, formid id) const;
        DATA get(formid id) const;
        Block getBlock(formid id) const;
    private:
        MapHash<DATA> *cellCols;
    };

};
#endif	/* GCELL_HPP */

