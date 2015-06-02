/* 
 * File:   main.cpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 27 Январь 2015 г., 19:16
 */

#include <Groups/GroupCell.hpp>
#include <Reader.hpp>
#include <iostream>
#include <Record.hpp>
#include <gtest/gtest.h>
#include <boost/variant/get.hpp>
using namespace std;

string hexAlign(uint32_t value)
{
    std::stringstream sstr;
    sstr << "0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << value;
    return sstr.str();
}

TEST(ReaderTest, testReaderESM)
{
    freopen("error.log", "w", stderr);
    if(Reader::GetSelf() == nullptr)
        Reader::Create();
    Reader *reader = Reader::GetSelf();
    ASSERT_TRUE(nullptr != reader);
    reader->Load("data//Fallout3.esm");
    
    
    ASSERT_EQ (reader->weapons.size(), 160);
    ASSERT_EQ (reader->npcs.size(), 1647);
    ASSERT_EQ (reader->armors.size(), 237);
    
    GroupCELL::Helper chelp(&reader->mapCells);
    GroupCELL::DATA cell = chelp.get(0x00003A34);
    cout << cell.cell.edid << endl;
    cout << cell.persistent.placedObjects.size() << endl;
    cout << cell.persistent.placedObjects[0x00003DE3].positionRotation.xPos << endl;
    
    
    /*for (const auto data : reader->gameSettings)
    {
        cout << hexAlign(data.first) << "\t" << data.second.edid << " " << data.second.variable << endl;
    }
    
    for (const auto data : reader->weapons)
    {
        
        cout << "------------------- ID: " << hexAlign(data.first) << " -------------------" << endl;
        cout << "Editor ID: " << data.second.edid  << endl;
        cout << "Clips: " << to_string(data.second.data.ClipSize) << " Base damage: " << data.second.data.baseDamage << endl;
        cout << "Ammo editor id: " << reader->ammo[data.second.ammoId].edid << " (" + hexAlign(data.second.ammoId) + ")" << endl;
        cout << data.second.destruction.dest.health << endl;
    }*/
    
    ASSERT_FLOAT_EQ(0.94, reader->GetFileVersion());
   
    EXPECT_STREQ("ipely", reader->GetFileAuthor().c_str());
    EXPECT_STREQ("", reader->GetFileDescription().c_str());
    Reader::Destroy();
    reader = nullptr;
}

TEST(ReaderTest, testPerk)
{
    if(Reader::GetSelf() == nullptr)
        Reader::Create();
    Reader *reader = Reader::GetSelf();
    ASSERT_TRUE(nullptr != reader);
    
    reader->Load("data//testPerk.esp");
    
    cout << "PERKS: " << reader->perks.size()<<endl;
    
    for (const auto perk_pair : reader->perks)
    {
        cout << "EDID: " << perk_pair.second.edid << endl;
        cout << "FunctionType: " << (int)perk_pair.second.effects.back().entryPointFunctionType << endl;
        if(perk_pair.second.effects.back().header.type ==  RecordPERK::DATA::Effect::Header::Type::EntryPoint)
        {
            RecordPERK::DATA::Effect::EntryPointData epd = boost::get<RecordPERK::DATA::Effect::EntryPointData>(perk_pair.second.effects.back().data);
            cout << "entryPoint: " << (int)epd.entryPoint << endl;
            cout << "function: " << (int)epd.function << endl;
            cout << "Tabs: " << (int)epd.perkConditionTabCount << endl;
        }
        
        
        if(perk_pair.second.effects.back().entryPointFunctionType == 1)
        {
           cout << "Function Data: "<< boost::get<float>(perk_pair.second.effects.back().entryPointFunctionData) << endl;
        }
        else if(perk_pair.second.effects.back().entryPointFunctionType == 2)
        {
            cout << "Function Data 1: "<< boost::get<RecordPERK::DATA::Effect::EPFD_2>(perk_pair.second.effects.back().entryPointFunctionData).val0 << endl;
            cout << "Function Data 2: "<< boost::get<RecordPERK::DATA::Effect::EPFD_2>(perk_pair.second.effects.back().entryPointFunctionData).val1 << endl;
        }
        else if(perk_pair.second.effects.back().entryPointFunctionType == 4)
        {
            
        }
    }
    
    Reader::Destroy();
}

TEST(ReaderTest, testDestroy)
{
    if(Reader::GetSelf() == nullptr)
        Reader::Create();
    Reader::Destroy();
}

TEST(ReaderTest, testReaderESP)
{
    if(Reader::GetSelf() == nullptr)
        Reader::Create();
    Reader *reader = Reader::GetSelf();
    ASSERT_TRUE(nullptr != reader);
    reader->Load("data//testArmor.esp");
    
    ASSERT_EQ (reader->armors.size(), 2);
    
    EXPECT_STREQ("TEST_ARMOR", reader->GetFileAuthor().c_str());
    EXPECT_STREQ("TEST DESCRIPTION", reader->GetFileDescription().c_str()); 
    ASSERT_FLOAT_EQ(0.94, reader->GetFileVersion());
    Reader::Destroy();
}