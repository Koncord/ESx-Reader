#include "SubRecord.hpp"

SubRecHeader SubRecord::ReadHeader(uint8_t *data, uint32_t *pos)
{
    SubRecHeader rec = *(reinterpret_cast<SubRecHeader*>(&data[*pos]));
    *pos += sizeof(SubRecHeader);
    return rec;
}
