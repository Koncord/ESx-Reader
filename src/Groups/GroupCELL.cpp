/* 
 * File:   CELL.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 29 Май 2015 г., 6:42
 */

#include "GroupCELL.hpp"

GroupCELL::Helper::Helper(MapHash<DATA>* cellCols)
{
    this->cellCols = cellCols;
}

IDHash<GroupCELL::DATA> GroupCELL::Helper::get(Block block) const
{
    return cellCols->at(block);
}

GroupCELL::DATA GroupCELL::Helper::get(Block block, formid id) const
{
    return (cellCols->at(block))[id];
}

GroupCELL::DATA GroupCELL::Helper::get(formid id) const
{

    for (MapHash<DATA>::iterator it = cellCols->begin(); it != cellCols->end(); ++it)
    {
        return it->second.find(id)->second;
    }
}

Block GroupCELL::Helper::getBlock(formid id) const
{
    for (MapHash<DATA>::iterator it = cellCols->begin(); it != cellCols->end(); ++it)
    {
        for (IDHash<DATA>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
        {
            if (it2->first == id)
                return it->first;
        }
    }
}

void GroupCELL::Helper::insert(Block block, IDHash<GroupCELL::DATA> cells)
{
    cellCols->at(block) = cells;
}
