#include "Reader.hpp"

#include <stdexcept>
#include <memory>

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

static Reader *reader = nullptr;

inline void WhileByGroup(GroupHeader group, std::function<void()> func)
{
    const unsigned var = static_cast<uint32_t>(reader->file.tellg()) + group.size - sizeof(GroupHeader);
    while(reader->file.tellg() < var && !reader->file.eof())
    {
        func();
    }
}

template<typename ClassOfRecord, typename HashData>
inline bool ParseGroup(GroupHeader group, const string &label, IDHash<HashData> *hashData )
{
    if(string(group.label, 4) == label)
    {
        WhileByGroup(group, [&]() mutable 
        {
            ClassOfRecord rec;
            (*hashData)[rec.head.id] = rec.data;
        });
        return true;
    }
    return false;
}

bool ParsingClildren(GroupHeader header, GroupCELL::DATA *cell);

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

    const RecHeader head = Record::ReadHeader();

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
        const GroupHeader ghead = Group::ReadHeader();
        if(ghead.groupType != GroupHeader::Type::TopLevel)
            continue;
        
#define PARSE_GROUP(_ClassOfRecord, _label, _IDHashData) \
if (ParseGroup<_ClassOfRecord, _ClassOfRecord::DATA>(ghead, _label, &_IDHashData)) \
    continue;
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
        PARSE_GROUP(RecordPACK, "PACK", packages); 
#undef PARSE_GROUP

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
            WhileByGroup(ghead, [&]() mutable
            {
                const GroupHeader gBlockHead = Group::ReadHeader();
                if(gBlockHead.groupType == GroupHeader::Type::InteriorCellBlock)
                {
                    const uint32_t cellBlock = *(reinterpret_cast<const uint32_t*> (gBlockHead.label));

                    WhileByGroup(gBlockHead, [&]() mutable
                    {
                        const GroupHeader gSubBlockHead = Group::ReadHeader();
                        if(gSubBlockHead.groupType == GroupHeader::Type::InteriorCellSubBlock)
                        {
                            const uint32_t cellSubBlock = *(reinterpret_cast<const uint32_t*> (gSubBlockHead.label));

                            IDHash<GroupCELL::DATA> gcells = treeCells[Block(cellBlock, cellSubBlock)];
                            WhileByGroup(gSubBlockHead, [&]() mutable
                            {
                                static formid id = 0;
                                const RecHeader head = Record::ReadHeader();

                                if(string(head.type, 4) == "CELL")
                                {
                                    RecordCELL rec(head);
                                    gcells[rec.head.id].cell = rec.data;
                                    id = rec.head.id;
                                    return;
                                }

                                FIXME(ugly hack)
                                const GroupHeader h = *(reinterpret_cast<const GroupHeader*>(&head));
                                if(ParsingClildren(h, &gcells[id])) return;
                            });
                            treeCells[Block(cellBlock, cellSubBlock)] = gcells;
                        }
                    });
                }
            });
            continue;
        }

        if(string(ghead.label,4) == "WRLD")
        {
            static formid wrld_id;
            WhileByGroup(ghead, [&]() mutable
            {
                const RecHeader head = Record::ReadHeader();

                if(string(head.type, 4) == "WRLD")
                {
                    RecordWRLD rec(head);
                    wrld_id = rec.head.id;
                    worldspace[wrld_id].wrld = rec.data;
                    return;
                }



                const GroupHeader gWorldChildren = *(reinterpret_cast<const GroupHeader*>(&head));

                if(gWorldChildren.groupType == GroupHeader::Type::WorldChildren)
                {
                    WhileByGroup(gWorldChildren, [&]() mutable
                    {
                        const RecHeader head = Record::ReadHeader();
                        if(string(head.type, 4) == "CELL")
                        {
                            RecordCELL rec(head);
                            worldspace[wrld_id].cell.cell = rec.data;
                            return;
                        }

                        const GroupHeader gExteriorCellBlock = *(reinterpret_cast<const GroupHeader*>(&head));
                        if(ParsingClildren(gExteriorCellBlock, &worldspace[wrld_id].cell)) 
                            return;

                        if(gExteriorCellBlock.groupType == GroupHeader::Type::ExteriorCellBlock)
                        {
                            const int8_t *block = static_cast<const int8_t*>(static_cast<const void*>(&gExteriorCellBlock.label));

                            GroupWRLD::MapCELL *mapCell = &worldspace[wrld_id].treeCells[Block(block[0], block[1])];

                            WhileByGroup(gExteriorCellBlock, [&]() mutable
                            {
                                GroupHeader gExteriorSubCellBlock = Group::ReadHeader();
                                WhileByGroup(gExteriorSubCellBlock, [&]() mutable
                                {
                                    const GroupHeader h = Group::ReadHeader();
                                    const RecHeader head = *(reinterpret_cast<const RecHeader*>(&h));

                                    const uint8_t *subBlock = static_cast<const uint8_t*>(static_cast<const void*>(&gExteriorSubCellBlock.label));

                                    static formid id = 0;

                                    IDHash<GroupCELL::DATA> *gcells = &((*mapCell)[Block(subBlock[0], subBlock[1])]);

                                    if(string(head.type, 4) == "CELL")
                                    {
                                        RecordCELL rec(head);
                                        id = rec.head.id;
                                        (*gcells)[id].cell = rec.data;
                                        return;
                                    }
                                    if(ParsingClildren(h, &(*gcells)[id]))
                                        return;
                                });
                            });
                        }
                    });
                }
            });
            continue;
        }

        // if unhandled group ---------------------------------------------+
        #ifdef DEBUG                                                    // |
        cerr << "WARNING! Unhandled group: " << string(ghead.label, 4)  // |
             << " position: " << to_string(file.tellg()) << endl;       // |
        #endif                                                          // |
        file.ignore(ghead.size - sizeof(GroupHeader)); // <----------------+
    }

    file.close();
}

Reader::~Reader()
{

}

bool ParsingClildren(GroupHeader head, GroupCELL::DATA *cell)
{
    if(head.groupType != GroupHeader::Type::CellChildren)
        return false;
    WhileByGroup(head, [&]() mutable
    {
        GroupHeader gChildrenHead = Group::ReadHeader();
        if (gChildrenHead.groupType == GroupHeader::Type::CellPersistentChildren)
        {
            WhileByGroup(gChildrenHead, [&]() mutable
            {
                const RecHeader rhead = Record::ReadHeader();
                const string type = string(rhead.type, 4);
                if (type == "REFR")
                {
                    RecordREFR rec(rhead);
                    cell->persistent.placedObjects[rec.head.id] = rec.data;
                }
                else if (type == "ACRE")
                {
                    RecordACRE rec(rhead);
                    cell->persistent.placedCreatures[rec.head.id] = rec.data;
                }
                else if (type == "ACHR")
                {
                    RecordACHR rec(rhead);
                    cell->persistent.placedNPCs[rec.head.id] = rec.data;
                }
                else if (type == "PGRE")
                {
                    RecordPGRE rec(rhead);
                    cell->persistent.placedGrenades[rec.head.id] = rec.data;
                }
                else if (type == "PMIS")
                {
                    RecordPMIS rec(rhead);
                    cell->persistent.placedMissiles[rec.head.id] = rec.data;
                }
                else  if(type == "LAND" || type == "NAVM")
                    reader->file.ignore(rhead.dataSize);
            });
        }
        else if (gChildrenHead.groupType == GroupHeader::Type::CellTemporaryChildren)
        {
            WhileByGroup(gChildrenHead, [&]() mutable
            {
                const RecHeader rhead = Record::ReadHeader();
                const string type = string(rhead.type, 4);
                if (type == "REFR")
                {
                    RecordREFR rec(rhead);
                    cell->temporary.placedObjects[rec.head.id] = rec.data;
                }
                else if (type == "ACRE")
                {
                    RecordACRE rec(rhead);
                    cell->temporary.placedCreatures[rec.head.id] = rec.data;
                }
                else if (type == "ACHR")
                {
                    RecordACHR rec(rhead);
                    cell->temporary.placedNPCs[rec.head.id] = rec.data;
                }
                else if (type == "PGRE")
                {
                    RecordPGRE rec(rhead);
                    cell->temporary.placedGrenades[rec.head.id] = rec.data;
                }
                else if (type == "PMIS")
                {
                    RecordPMIS rec(rhead);
                    cell->temporary.placedMissiles[rec.head.id] = rec.data;
                }
                else  if(type == "LAND" || type == "NAVM")
                    reader->file.ignore(rhead.dataSize);
            });
        }
        else
            throw runtime_error("Fail read CellChildren on pos: " + to_string(reader->file.tellg()));
    });
    return true;
}
