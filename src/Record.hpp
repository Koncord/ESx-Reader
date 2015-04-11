#ifndef RECORD_HPP
#define RECORD_HPP
#include <cstdint>
#include <memory>
#include <vector>
#include "Group.hpp"
#include "SubRecord.hpp"
#include "Types.hpp"
#include "Subrecords/CollectionEffect.hpp"
#include "Subrecords/ScriptCollection.hpp"
#include "Subrecords/DestructionCollection.hpp"
#include "Subrecords/ItemCollection.hpp"
#include "debug_macros.hpp"

typedef enum
{
    isMaster = 0x00000001,
    isDeleted = 0x00000020,
    isBorderRegion = 0x00000040,
    isConstant = 0x00000040,
    isHiddenFromLocalMap = 0x00000040,
    isTurnOffFire = 0x00000080,
    isInaccessible = 0x00000100,
    isOnLocalMap = 0x00000200,
    isQuestItem = 0x00000400,
    isInitiallyDisabled = 0x00000800,
    isIgnored = 0x00001000,
    isNoVoiceFilter = 0x00002000,
    isVisibleWhenDistant = 0x00008000,
    isRandomAnimStart = 0x00010000,
    isDangerous = 0x00020000,
    isOffLimits = 0x00020000,
    isInteriorCell = 0x00020000,
    isCompressed = 0x00040000,
    isCantWait = 0x00080000,
    isObstacle = 0x02000000,
    isNoAIAcquire = 0x02000000,
    isNavMeshGenerationFilter = 0x04000000,
    isNavMeshGenerationBoundingBox = 0x08000000,
    isNonPipboy = 0x10000000,
    isChildCanUse = 0x20000000,
    isNavMeshGenerationGround = 0x40000000
} Flag;

struct RecHeader
{
    char type[4];
    uint32_t dataSize;
    uint32_t flags;
    formid id;
    uint32_t revision;
    uint16_t version;
};

class Record
{

public:
    RecHeader head;

protected:
    SubRecHeader subhead;
    
    struct RAWDATA
    {
        std::unique_ptr<uint8_t[]> data;
        uint32_t pos;
        uint32_t size;
    } rawdata;

    template<class T>
    T GetData()
    {
        T tmp = *(reinterpret_cast<T*> (&rawdata.data.get()[rawdata.pos]));
        rawdata.pos += sizeof (T);
        return tmp;
    }
    
    template<class T>
    T GetData(uint32_t size)
    {
        T tmp = *(reinterpret_cast<T*> (&rawdata.data.get()[rawdata.pos]));
        rawdata.pos += size;
        return tmp;
    }
    
    std::string GetString()
    {
        std::string str((char*) &rawdata.data.get()[rawdata.pos], subhead.dataSize-1);
        rawdata.pos += subhead.dataSize;
        return str;
    }
    
    std::vector<uint8_t> GetRawData()
    {
        uint8_t *t = (uint8_t*)&rawdata.data.get()[rawdata.pos];
        std::vector<uint8_t> tmp(t, t+subhead.dataSize);
        
        rawdata.pos += subhead.dataSize;
        
        return tmp;
    }
    
    const std::string GetLabel() {return std::string(subhead.type, 4);}
    void ParseHead(const RecHeader &head);
    void ReadSubHeader();
    void IgnoreBytes(uint32_t value) { rawdata.pos += value; }
    void IgnoreSubRecord() { IgnoreBytes(subhead.dataSize); }
    
    // --------------------- SubRecord collections -----------------------------
    bool ModelCollection();
    bool DestructionData(Destruction *destruction);
    bool ConditionsData(CTDA *cond);
    bool ItemCollection(Items *items);
    bool ScriptCollection(Script *scr);
    bool EffectCollection(Effect * effect);
    // -------------------------------------------------------------------------
protected:
    virtual bool DoParse() = 0;
    explicit Record(const RecHeader &head);
    Record();
    virtual ~Record();

public:

    bool GetFlag(Flag flag) { return head.flags & flag; }
    static RecHeader ReadHeader();
    void Parse();
};

#endif // RECORD_HPP
