#ifndef READER_HPP
#define READER_HPP

#include <fstream>

#include "Types.hpp"

#include "debug_macros.hpp"

#include "Records/GMST.hpp"
#include "Records/TES4.hpp"
#include "Records/WEAP.hpp"
#include "Records/GLOB.hpp"
#include "Records/CONT.hpp"
#include "Records/AMMO.hpp"
#include "Records/TERM.hpp"
#include "Records/SCPT.hpp"
#include "Records/BOOK.hpp"
#include "Records/NPC_.hpp"
#include "Records/MISC.hpp"
#include "Records/ALCH.hpp"
#include "Records/FACT.hpp"
#include "Records/CLAS.hpp"
#include "Records/ARMO.hpp"
#include "Records/ARMA.hpp"
#include "Records/FLST.hpp"
#include "Records/REFR.hpp"
#include "Records/KEYM.hpp"
#include "Records/EXPL.hpp"
#include "Records/PERK.hpp"
#include "Records/DOOR.hpp"
#include "Records/ECZN.hpp"
#include "Records/CPTH.hpp"
#include "Records/RADS.hpp"
#include "Records/ACTI.hpp"
#include "Records/TACT.hpp"
#include "Records/STAT.hpp"
#include "Records/IDLM.hpp"
#include "Records/ANIO.hpp"


class Reader
{
public:
    template<class T>
    T ReadRaw()
    {
        T tmp;
        file.read((char*)&tmp, sizeof(T));
        return tmp;
    }
    
    uint8_t *ReadData(uint8_t *data, size_t size);
    void Load(std::string file);
    ~Reader();
    float GetFileVersion() { return data.hedr.version; }
    std::string GetFileAuthor() { return data.author; }
    std::string GetFileDescription() { return data.description; }

private:
    Reader();
    RecordTES4::DATA data;
    
public:
    std::ifstream file;
public:
    static Reader *GetSelf();
    static Reader *Create();
    static void Destroy();
    
public:
    IDHash<RecordGMST::DATA> gameSettings;
    IDHash<RecordWEAP::DATA> weapons;
    IDHash<RecordGLOB::DATA> globals;
    IDHash<RecordCONT::DATA> containers;
    IDHash<RecordAMMO::DATA> ammo;
    IDHash<RecordTERM::DATA> terminals;
    IDHash<RecordSCPT::DATA> scripts;
    IDHash<RecordBOOK::DATA> books;
    IDHash<RecordNPC_::DATA> npcs;
    IDHash<RecordMISC::DATA> miscItems;
    IDHash<RecordALCH::DATA> ingestibles;
    IDHash<RecordFACT::DATA> factions;
    IDHash<RecordCLAS::DATA> classes;
    IDHash<RecordARMO::DATA> armors;
    IDHash<RecordARMA::DATA> armorAddons;
    IDHash<RecordFLST::DATA> formIdLists;
    IDHash<RecordREFR::DATA> placedObjects;
    IDHash<RecordKEYM::DATA> keys;
    IDHash<RecordEXPL::DATA> explosions;
    IDHash<RecordPERK::DATA> perks;
    IDHash<RecordDOOR::DATA> doors;
    IDHash<RecordECZN::DATA> encounterZones;
    IDHash<RecordCPTH::DATA> cameraPaths;
    IDHash<RecordRADS::DATA> radStages;
    IDHash<RecordACTI::DATA> activators;
    IDHash<RecordTACT::DATA> talkingActivators;
    IDHash<RecordSTAT::DATA> staticObjects;
    IDHash<RecordIDLM::DATA> idleMarker;
    IDHash<RecordANIO::DATA> animatedObject;
};

#endif // READER_HPP
