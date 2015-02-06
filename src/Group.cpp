#include "Group.hpp"
#include "Reader.hpp"

GroupHeader Group::ReadHeader()
{
    return Reader::GetSelf()->ReadRaw<GroupHeader>();
}


void Group::Parse()
{
    
}
