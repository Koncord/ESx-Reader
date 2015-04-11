/* 
 * File:   QUST.hpp
 * Author: Koncord <koncord at rwa.su>
 *
 * Created on 11 Апрель 2015 г., 21:51
 */

#ifndef QUST_HPP
#define	QUST_HPP

#include "../Record.hpp"
class RecordQUST : public Record
{
public:

    struct DATA
    {
        std::string edid;
        formid script; // FormID of a SCPT record.
        std::string name;
        std::vector<CTDA> conditions;
#pragma pack(push, 1)
        struct _DATA
        {
            uint8_t flags;
            uint8_t priority;
            int16_t unused;
            float questDelay;
            enum Flag
            {
                StartGameEnabled = 0x01,
                Unknown1 = 0x02,
                AllowRepeatedConversationTopics = 0x04,
                AllowRepeatedStages = 0x08,
                Unknown2 = 0x10
            };
        } data;
        struct Stage
        {
            int16_t stageIndex;
            struct LogEntry
            {
                uint8_t stageFlag;
                std::vector<CTDA> conditions;
                std::string logEntry;
                Script embeddedScript;
                formid nextQuest;
                enum StageFlag
                {
                    CompleteQuest = 0x01,
                    FailQuest = 0x02
                };
            };
            std::vector<LogEntry> logEntrys;
        };
        std::vector<Stage> stages;
        struct Objective
        {
            int32_t objectiveIndex;
            std::string description;
            struct Target
            {
                struct _Target
                {
                    formid target;
                    uint8_t flags;
                    int8_t unused[3];
                    enum Flag
                    {
                        CompassMarkerIgnoresLocks = 0x01
                    };
                }target;
                std::vector<CTDA> conditions;
            };
            std::vector<Target> targets;
        };
        std::vector<Objective> objectives;
#pragma pack(pop)
    } data;

    explicit RecordQUST(const RecHeader &head) : Record(head) { Parse(); }

    RecordQUST() : Record() { Parse(); }
    virtual bool DoParse();
};

#endif	/* QUST_HPP */

