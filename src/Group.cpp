#include "Group.hpp"
#include "Reader.hpp"

GroupHeader Group::ReadHeader()
{
    GroupHeader header;
    Reader::GetSelf()->ReadData((uint8_t*)&header, sizeof(GroupHeader));
    return header;
}


void Group::Parse()
{
    
}
