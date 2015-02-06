#ifndef TES4_HPP
#define TES4_HPP
#include "../Record.hpp"
#include <list>
class RecordTES4 : public Record
{
protected:

public:

#pragma pack(push, 1)
    struct DATA
    {
        RecHeader header;
        struct HEDR
        {
            float version;
            uint32_t numRecords;
            uint32_t nextObjID;
        } hedr;
        std::string author;
        std::string description;
        std::list<std::string> masters;
        std::list<uint32_t> formOverrides;
    }data;
#pragma pack(pop)

    explicit RecordTES4(const RecHeader &head) : Record(head) { Parse();}
    virtual bool DoParse();

    inline bool isTypeMaster()
    {
        return GetFlag(Flag::isMaster);
    }
};

#endif // TES4_HPP
