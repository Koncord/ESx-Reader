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
    
    if(file.is_open()) throw std::runtime_error("At one point in time may e read only one file");
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
        if(ghead.groupType == GroupType::TopLevel)
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
            todo(RecordRACE)
            todo(RecordMGEF)
            todo(RecordENCH)
            todo(RecordSPEL)
            todo(RecordINGR)
            todo(RecordLIGH)
            todo(RecordSTAT)
            todo(RecordSCOL)
            todo(RecordMSTT)
            todo(RecordPWAT)
            todo(RecordTREE)           
            todo(RecordFURN)     
            todo(RecordCREA)
            todo(RecordLVLC)
            todo(RecordLVLN)
            todo(RecordALCH)        
            todo(RecordPROJ)
            todo(RecordLVLI)
            todo(RecordWTHR)
            todo(RecordCLMT)
            todo(RecordCOBJ)
            todo(RecordREGN)
            todo(RecordNAVI)
            todo(RecordDIAL)
            todo(RecordQUST)
            todo(RecordIDLE)
            todo(RecordPACK)
            todo(RecordCSTY)
            todo(RecordANIO)
            todo(RecordWATR)
            todo(RecordDEBR)
            todo(RecordBPTD)
            todo(RecordADDN)
            todo(RecordCAMS)
            todo(RecordMESG)
            todo(RecordDOBJ)
                    
            NOTE(-----------------------------------------------------------)
            NOTE(the following records may not be needed for multiplayer)
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
            NOTE(-----------------------------------------------------------)
                    
            if(string(ghead.label,4) == "CELL")
            {
                WHILE_BY_GRUP(ghead, endBlockGroup)
                {
                    GroupHeader gBlockHead = Group::ReadHeader();
                    if(gBlockHead.groupType == GroupType::InteriorCellBlock)
                    {
                        //uint32_t cellBlock = *(reinterpret_cast<uint32_t*> (gBlockHead.label));
                        
                        WHILE_BY_GRUP(gBlockHead, endSubBlockGroup)
                        {
                            GroupHeader gSubBlockHead = Group::ReadHeader();
                            if(gSubBlockHead.groupType == GroupType::InteriorCellSubBlock)
                            {
                                //uint32_t cellSubBlock = *(reinterpret_cast<uint32_t*> (gSubBlockHead.label));
                                
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
                                        if(h.groupType == GroupType::CellPersistentChildren)
                                        {
                                           file.ignore(h.size - sizeof(GroupHeader));
                                        }
                                        else if(h.groupType == GroupType::CellTemporaryChildren)
                                        {
                                            file.ignore(h.size - sizeof(GroupHeader));
                                        }
                                        else if(h.groupType == GroupType::CellChildren)
                                        {
                                            file.ignore(h.size - sizeof(GroupHeader));
                                        }
                                        else
                                        {
                                            throw runtime_error (to_string(file.tellg()) + " Unknown type: " + to_string(h.groupType));
                                        }
                                        //cout << "POS: " << file.tellg() << endl;
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
