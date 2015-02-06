#include "../SubRecord.hpp"
class subEDID : public SubRecord
{
public:
    void Read();
    char * GetData();
};
