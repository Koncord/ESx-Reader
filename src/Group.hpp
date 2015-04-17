#ifndef GROUP_HPP
#define GROUP_HPP

#include <cstdint>



struct GroupHeader
{
    char type[4];
    uint32_t size;
    char label[4];
    uint32_t groupType;
    uint16_t stamp;
    char unknown_bytes[6];
    enum Type
    {
        TopLevel = 0,
        WorldChildren,
        InteriorCellBlock,
        InteriorCellSubBlock,
        ExteriorCellBlock,
        ExteriorCellSubBlock,
        CellChildren,
        TopicChildren,
        CellPersistentChildren,
        CellTemporaryChildren,
        CellVisibleDistantChildren
    };
};

class Group
{
protected:
    GroupHeader head;
public:

    static GroupHeader ReadHeader();

    virtual void Parser() = 0;
    void Parse();
};

#endif // GROUP_HPP
