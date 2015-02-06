#ifndef GMST_HPP
#define GMST_HPP
#include "../Record.hpp"

#include <boost/variant/variant.hpp>

enum DataType
{
    String = 's',
    Float = 'f',
    Integer = 'i'
};

class RecordGMST : public Record
{
public:
    struct DATA
    {
        std::string edid;
        boost::variant<float, uint32_t, std::string> variable;
        char GetType() { return edid[0]; }
    } data;
    explicit RecordGMST(const RecHeader &head) : Record(head){Parse(); }
    RecordGMST() : Record() {Parse();}
    virtual bool DoParse();
    char GetType();
};

#endif //GMST_HPP
