#include "GMST.hpp"
#include "../SubRecord.hpp"
#include "../Subrecords/subEDID.hpp"
#include "../Reader.hpp"

using namespace std;

char RecordGMST::GetType()
{
    return data.edid[0];
}

bool RecordGMST::DoParse()
{
    if (GetLabel() == "EDID")
    {
        this->data.edid = this->GetString();
    }
    else if (GetLabel() == "DATA")
    {
        if (GetType() == DataType::Float)
            data.variable = GetData<float>();
        else if (GetType() == DataType::Integer)
            data.variable = GetData<uint32_t>();
        else if (GetType() == DataType::String)
            data.variable = GetString();
    }
    else return false;
    return true;
}
