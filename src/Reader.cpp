#include "Reader.hpp"

#include <stdexcept>
#include <memory>

#include <iostream>
#include <cstring>
using namespace std;

static Reader *reader = nullptr;

#define GRUP_SIZE(group, varname) uint32_t varname = static_cast<uint32_t>(file.tellg()) + group.size - sizeof(GroupHeader)
#define WHILE_BY_GRUP(group, varname) GRUP_SIZE(group, varname); while(file.tellg() < varname && !file.eof())
#define PARSE_GROUP(_ClassOfRecord, _label, _IDHashData)                                        \
if(string(ghead.label,4) == _label)                                                             \
{                                                                                               \
    WHILE_BY_GRUP(ghead, endGroup)                                                              \
    {                                                                                           \
        _ClassOfRecord rec; _IDHashData[rec.head.id] = rec.data;                                \
    }                                                                                           \
    continue;                                                                                   \
}

Reader::Reader()
{
}

Reader* Reader::Create()
{
    if(reader != nullptr) throw std::runtime_error("only one instance must be created.");
    reader = new Reader;
    return reader;
}


void Reader::Destroy()
{
    if(reader == nullptr) throw std::runtime_error("nothing to destroy");
    delete reader;
    reader = nullptr;
}

Reader* Reader::GetSelf()
{
    //if(reader == nullptr) throw std::runtime_error("The reader is not created!");
    return reader;
}

uint8_t *Reader::ReadData(uint8_t *data, size_t size)
{
    if(file.eof()) throw runtime_error("End of file");
    file.read((char*)data, size);
    return data;
}

void Reader::Load(std::string path)
{
    
    if(file.is_open()) throw std::runtime_error("At one point in the ESx-Reader time may read only one file");
    file.open(path, ifstream::binary);
    
    if(!file.is_open()) throw std::runtime_error("file can\'t be opened!");
    
    auto head = Record::ReadHeader();
    
    std::string type(head.type, 4);
    
    if(type == "TES4")
    {
        RecordTES4 tes4(head);
        data = tes4.data;
    }
    else
        throw runtime_error("unkown file type: " + type);
    
    while(!file.eof())
    {
        GroupHeader ghead = Group::ReadHeader();
        if(ghead.groupType == GroupHeader::Type::TopLevel)
        {
            PARSE_GROUP(RecordGMST, "GMST", gameSettings);
            PARSE_GROUP(RecordWEAP, "WEAP", weapons);
            PARSE_GROUP(RecordGLOB, "GLOB", globals);
            PARSE_GROUP(RecordCONT, "CONT", containers);
            PARSE_GROUP(RecordAMMO, "AMMO", ammo);
            PARSE_GROUP(RecordTERM, "TERM", terminals);
            PARSE_GROUP(RecordSCPT, "SCPT", scripts);
            PARSE_GROUP(RecordBOOK, "BOOK", books);
            PARSE_GROUP(RecordNPC_, "NPC_", npcs);
            PARSE_GROUP(RecordMISC, "MISC", miscItems);
            PARSE_GROUP(RecordALCH, "ALCH", ingestibles);
            PARSE_GROUP(RecordFACT, "FACT", factions);
            PARSE_GROUP(RecordCLAS, "CLAS", classes);
            PARSE_GROUP(RecordARMO, "ARMO", armors);
            PARSE_GROUP(RecordARMA, "ARMA", armorAddons);
            PARSE_GROUP(RecordFLST, "FLST", formIdLists);
            PARSE_GROUP(RecordKEYM, "KEYM", keys);
            PARSE_GROUP(RecordEXPL, "EXPL", explosions);
            PARSE_GROUP(RecordPERK, "PERK", perks);
            PARSE_GROUP(RecordDOOR, "DOOR", doors);
            PARSE_GROUP(RecordECZN, "ECZN", encounterZones);
            PARSE_GROUP(RecordCPTH, "CPTH", cameraPaths);
            PARSE_GROUP(RecordRADS, "RADS", radStages);
            PARSE_GROUP(RecordACTI, "ACTI", activators);
            PARSE_GROUP(RecordTACT, "TACT", talkingActivators);
            PARSE_GROUP(RecordSTAT, "STAT", staticObjects);
            PARSE_GROUP(RecordIDLM, "IDLM", idleMarker);
            PARSE_GROUP(RecordANIO, "ANIO", animatedObject);
            PARSE_GROUP(RecordCAMS, "CAMS", cameraShots);
            PARSE_GROUP(RecordFURN, "FURN", furniture);
            PARSE_GROUP(RecordINGR, "INGR", ingredients);
            PARSE_GROUP(RecordMGEF, "MGEF", magicEffects);
            PARSE_GROUP(RecordENCH, "ENCH", objectEffects);
            PARSE_GROUP(RecordSPEL, "SPEL", actorEffects);
            PARSE_GROUP(RecordLIGH, "LIGH", light);
            PARSE_GROUP(RecordSCOL, "SCOL", staticCollections);
            PARSE_GROUP(RecordMSTT, "MSTT", movableStaticObjects);
            PARSE_GROUP(RecordPWAT, "PWAT", placeableWaters)
            PARSE_GROUP(RecordCOBJ, "COBJ", constructibleObjects);
            PARSE_GROUP(RecordLVLN_LVLC, "LVLN", leveledNPCs);
            PARSE_GROUP(RecordLVLN_LVLC, "LVLC", leveledCreatures);
            PARSE_GROUP(RecordLVLI, "LVLI", leveledItems);
            PARSE_GROUP(RecordDOBJ, "DOBJ", defaultObjectManager);
            PARSE_GROUP(RecordPROJ, "PROJ", projectiles);
            PARSE_GROUP(RecordQUST, "QUST", quests);
            PARSE_GROUP(RecordIDLE, "IDLE", idleAnimations);
            PARSE_GROUP(RecordBPTD, "BPTD", bodyPartData);
            PARSE_GROUP(RecordCSTY, "CSTY", combatStyles);
            PARSE_GROUP(RecordRACE, "RACE", race);
            PARSE_GROUP(RecordCREA, "CREA", creatures);
            PARSE_GROUP(RecordREGN, "REGN", regions);
            PARSE_GROUP(RecordWATR, "WATR", water);
                    
            todo(RecordPACK)
            
            NOTE(long term)
            todo(RecordNAVI)
            todo(RecordNAVM)
            
            NOTE(-----------------------------------------------------------)
            NOTE(the following records may not be needed for multiplayer)
            todo(RecordWTHR)
            todo(RecordCLMT)
            todo(RecordADDN)
            todo(RecordGRAS)
            todo(RecordTXST)
            todo(RecordMICN)
            todo(RecordHDPT)
            todo(RecordHAIR)
            todo(RecordEYES)
            todo(RecordASPC)
            todo(RecordLTEX)
            todo(RecordNOTE)
            todo(RecordEFSH)
            todo(RecordIMGS)
            todo(RecordIMAD)
            todo(RecordAVIF)
            todo(RecordVTYP)
            todo(RecordIPCT)
            todo(RecordIPDS)
            todo(RecordRGDL)
            todo(RecordLGTM)
            todo(RecordLSCR)
            todo(RecordMUSC)
            todo(RecordSOUN)
        
            NOTE(controversial records)
            todo(RecordDIAL)
            todo(RecordTREE)
            todo(RecordMESG)
            todo(RecordDEBR)
            NOTE(-----------------------------------------------------------)
                    
            if(string(ghead.label,4) == "CELL")
            {
                WHILE_BY_GRUP(ghead, endBlockGroup)
                {
                    GroupHeader gBlockHead = Group::ReadHeader();
                    if(gBlockHead.groupType == GroupHeader::Type::InteriorCellBlock)
                    {
                        WHILE_BY_GRUP(gBlockHead, endSubBlockGroup)
                        {
                            GroupHeader gSubBlockHead = Group::ReadHeader();
                            if(gSubBlockHead.groupType == GroupHeader::Type::InteriorCellSubBlock)
                            {
                                
                                WHILE_BY_GRUP(gSubBlockHead, gSubEnd)
                                {
                                    RecHeader head = Record::ReadHeader();
                                    if(string(head.type, 4) == "CELL")
                                    {
                                        todo(RecordCELL)
                                        file.ignore(head.dataSize);
                                        continue;
                                    }
                                    else
                                    {
                                        FIXME(ugly hack)
                                        GroupHeader h = *(reinterpret_cast<GroupHeader*>(&head));
                                        if(h.groupType == GroupHeader::Type::CellPersistentChildren)
                                        {
                                           todo(CellPersistentChildren)
                                           file.ignore(h.size - sizeof(GroupHeader));
                                        }
                                        else if(h.groupType == GroupHeader::Type::CellTemporaryChildren)
                                        {
                                            todo(CellTemporaryChildren)
                                            file.ignore(h.size - sizeof(GroupHeader));
                                        }
                                        else if(h.groupType == GroupHeader::Type::CellChildren)
                                        {
                                            todo(CellChildren)
                                            file.ignore(h.size - sizeof(GroupHeader));
                                        }
                                        else
                                        {
                                            throw runtime_error (to_string(file.tellg()) + " Unknown type: " + to_string(h.groupType));
                                        }
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }
                continue;
            }
            TODO(WRLD Parser)
            todo(RecordWRLD)
            // if unhandled group ---------------------------------------------+
            #ifdef DEBUG                                                    // |
            cerr << "WARNING! Unhandled group: " << string(ghead.label, 4)  // |
                 << " position: " << to_string(file.tellg()) << endl;       // |
            #endif                                                          // |
            file.ignore(ghead.size - sizeof(GroupHeader)); // <----------------+
    }
        }
        
    file.close();
}

Reader::~Reader()
{

}
