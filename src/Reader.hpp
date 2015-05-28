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
#include "Records/CAMS.hpp"
#include "Records/FURN.hpp"
#include "Records/INGR.hpp"
#include "Records/MGEF.hpp"
#include "Records/ENCH.hpp"
#include "Records/SPEL.hpp"
#include "Records/LIGH.hpp"
#include "Records/SCOL.hpp"
#include "Records/MSTT.hpp"
#include "Records/PWAT.hpp"
#include "Records/COBJ.hpp"
#include "Records/LVLN_LVLC.hpp"
#include "Records/LVLI.hpp"
#include "Records/DOBJ.hpp"
#include "Records/PROJ.hpp"
#include "Records/QUST.hpp"
#include "Records/IDLE.hpp"
#include "Records/BPTD.hpp"
#include "Records/CSTY.hpp"
#include "Records/RACE.hpp"
#include "Records/CREA.hpp"
#include "Records/REGN.hpp"
#include "Records/WATR.hpp"
#include "Records/PACK.hpp"

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
    IDHash<RecordCAMS::DATA> cameraShots;
    IDHash<RecordFURN::DATA> furniture;
    IDHash<RecordINGR::DATA> ingredients;
    IDHash<RecordMGEF::DATA> magicEffects;
    IDHash<RecordENCH::DATA> objectEffects;
    IDHash<RecordSPEL::DATA> actorEffects;
    IDHash<RecordLIGH::DATA> light;
    IDHash<RecordSCOL::DATA> staticCollections;
    IDHash<RecordMSTT::DATA> movableStaticObjects;
    IDHash<RecordPWAT::DATA> placeableWaters;
    IDHash<RecordCOBJ::DATA> constructibleObjects;
    IDHash<RecordLVLN_LVLC::DATA> leveledNPCs;
    IDHash<RecordLVLN_LVLC::DATA> leveledCreatures;
    IDHash<RecordLVLI::DATA> leveledItems;
    IDHash<RecordDOBJ::DATA> defaultObjectManager;
    IDHash<RecordPROJ::DATA> projectiles;
    IDHash<RecordQUST::DATA> quests;
    IDHash<RecordIDLE::DATA> idleAnimations;
    IDHash<RecordBPTD::DATA> bodyPartData;
    IDHash<RecordCSTY::DATA> combatStyles;
    IDHash<RecordRACE::DATA> race;
    IDHash<RecordCREA::DATA> creatures;
    IDHash<RecordREGN::DATA> regions;
    IDHash<RecordWATR::DATA> water;
    IDHash<RecordPACK::DATA> packages;
};

#endif // READER_HPP
