/* 
 * File:   BPTD.cpp
 * Author: Koncord <koncord at rwa.su>
 * 
 * Created on 16 Апрель 2015 г., 21:34
 */

#include "BPTD.hpp"

using namespace std;

bool RecordBPTD::DoParse()
{
    const string subType = GetLabel();
    if(subType == "EDID")
        data.edid = GetString();
    else if(subType == "RAGA")
        data.ragdoll = GetData<formid>();
    // --------------------- Body Part Subrecord Collection --------------------
    else if(subType == "BPTN")
    {
        data.bodyParts.push_back(DATA::BodyPart());
        data.bodyParts.back().partName = GetString();
    }
    else if(subType == "BPNN")
        data.bodyParts.back().partNode = GetString();
    else if(subType == "BPNT")
        data.bodyParts.back()._VATStarget = GetString();
    else if(subType == "BPNI")
        data.bodyParts.back()._IKData_StartNode = GetString();
    else if(subType == "BPND")
        data.bodyParts.back().nodeData = GetData<DATA::BodyPart::NodeData>();
    else if(subType == "NAM1")
        data.bodyParts.back().limbReplacementModel = GetString();
    else if(subType == "NAM4")
        data.bodyParts.back().goreEffects_TargetBone = GetString();
    else if(subType == "NAM5")
        IgnoreSubRecord();
    // -------------------------------------------------------------------------
    else if(ModelCollection()) {}
    else return false;
    return true;
}
