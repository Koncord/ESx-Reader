#ifndef TYPES_HPP
#define TYPES_HPP
#include <cstdint>
#include <unordered_map>
#include<cstdint>
#include <map>

typedef uint32_t formid;
typedef uint32_t rgba;
template <typename V>
using IDHash = std::unordered_map<formid, V>;

#endif // TYPES_HPP