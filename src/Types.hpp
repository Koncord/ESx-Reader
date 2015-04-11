#ifndef TYPES_HPP
#define TYPES_HPP
#include <cstdint>
#include <unordered_map>
#include<cstdint>
#include <map>
#include <vector>

typedef uint32_t formid;
typedef uint32_t rgba;
template <typename V>
using IDHash = std::unordered_map<formid, V>;

#pragma pack(push, 1)
struct OBND 
{
    uint16_t x1, y1, z1;
    uint16_t x2, y2, z2;
};
#pragma pack(pop)
#endif // TYPES_HPP