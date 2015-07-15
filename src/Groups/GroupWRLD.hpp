/* 
 * File:   GroupWRLD.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 2 Июль 2015 г., 14:40
 */

#ifndef GROUPWRLD_HPP
#define	GROUPWRLD_HPP

#include "GroupCELL.hpp"
#include "../Records/WRLD.hpp"

class GroupWRLD
{
public:

    typedef MapHash<GroupCELL::DATA> MapCELL;
    typedef std::unordered_map <Block, MapCELL > TreeCells;
    struct DATA
    {
        RecordWRLD::DATA wrld;
        GroupCELL::DATA cell;
        TreeCells treeCells;
    };

};

#endif	/* GROUPWRLD_HPP */

