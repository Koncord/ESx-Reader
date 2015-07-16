#ifndef TYPES_HPP
#define TYPES_HPP
#include <cstdint>
#include <unordered_map>
#include <cstdint>
#include <map>
#include <vector>
#include <boost/functional/hash.hpp>

typedef uint32_t formid;

struct rgba
{
    uint8_t r,g,b,a;
};

template <typename V>
using IDHash = std::unordered_map<formid, V>;

using Block = std::pair<int32_t, int32_t>;
template <typename V>
using MapHash = std::unordered_map <Block, IDHash<V>>;

namespace std
{
template<typename S, typename T> struct hash<pair<S, T>>
{

    inline size_t operator()(const pair<S, T> & v) const
    {
        size_t seed = 0;
        boost::hash_combine(seed, v.first);
        boost::hash_combine(seed, v.second);
        return seed;
    }
};
}

#pragma pack(push, 1)

struct ObjectBounds
{
    uint16_t x1, y1, z1;
    uint16_t x2, y2, z2;
};
#pragma pack(pop)
#endif // TYPES_HPP