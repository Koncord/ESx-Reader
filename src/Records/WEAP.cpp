/* 
 * File:   WEAP.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 30 Январь 2015 г., 21:16
 */

#include "WEAP.hpp"
#include "../Reader.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

bool RecordWEAP::DoParse()
{
    const std::string subType = GetLabel();
    if(subType == "EDID")
    {
        data.edid = GetString();
    }
    else if(subType == "OBND")
    {
        data.objectBounds = GetData<ObjectBounds>();
    }
    else if(subType == "FULL")
    {
        data.name = GetString();
    }
    else if(ModelCollection()) { }
    else if(subType == "EITM")
        data.objectEffectId = GetData<uint32_t>();
    else if(subType == "EAMT")
        IgnoreSubRecord();
    else if(subType == "NAM0")
        data.ammoId = GetData<uint32_t>(); // FormID of an AMMO or FLST record.
    else if(DestructionData(&data.destruction)) {/*throw std::runtime_error(std::to_string(head.id));*/}
    else if(subType == "REPL") // FormID of a FLST record.
        data.repairLstId= GetData<uint32_t>();
    else if(subType == "ETYP")
        data.etyp.equipType = GetData<int32_t>();
    else if(subType == "BIPL")
        IgnoreSubRecord(); //  	Biped Model List
    else if(subType == "YNAM" || subType == "ZNAM")
        IgnoreSubRecord(); // FormID of a SOUN record.
    else if(subType == "EFSD") 
        IgnoreSubRecord(); // Scope Effect;
    else if(subType == "NNAM")
        data.embeddedWeaponNode = GetString();
    else if(subType == "INAM")
        IgnoreSubRecord(); // ignore decals
    else if(subType == "WNAM")
        IgnoreSubRecord(); // First Person Model
    else if(subType == "SNAM" || subType == "XNAM" || subType == "NAM7" ||
            subType == "TNAM" || subType == "NAM6" || subType == "UNAM" ||
            subType == "NAM9" || subType == "NAM8")
        IgnoreSubRecord(); // FormID of a SOUN record.
    else if(subType == "DATA")
        data.data = GetData<DATA::_DATA>();
    else if(subType == "DNAM")
        data.dnam = GetData<DATA::DNAM>();
    else if(subType == "CRDT")
        data.crdt = GetData<DATA::CRDT>();
    else if(subType == "VNAM")
        data.soundLevel = GetData<uint32_t>();
    else if(subType == "ICON" || subType == "MICO")
        IgnoreSubRecord(); // ignore icons
    else if(subType == "SCRI")
        data.scriptId = GetData<uint32_t>();
    else
        return false;
    return true;
}
