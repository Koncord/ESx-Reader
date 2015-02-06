#ifndef SUBRECORD_HPP
#define SUBRECORD_HPP

#include <cstdint>

#pragma pack(push, 1)

struct SubRecHeader
{
    char type[4];
    uint16_t dataSize;
};
#pragma pack(pop)

class SubRecord
{
    
protected:
    SubRecHeader head;

public:
    SubRecord() { Read(); }
    virtual ~SubRecord() {};
    virtual void Read(){}
    static SubRecHeader ReadHeader(uint8_t *data, uint32_t *pos);
};

#endif // SUBRECORD_HPP
