#pragma once

#include "Src/Rules/rule.h"
#include "Src/Loggers/ConsolLogger/consollogger.h"
#include "Src/Loggers/FileLogger/filelogger.h"

#include "Src/Loggable/loggable.h"

template<bool consolLog, bool fileLog>
class LoggerRule : public Rule
{
public:
    LoggerRule()
    {
        if(consolLog)
        {
            _consolLogger = new ConsolLogger();
        }

        if(fileLog)
        {
            _fileLogger = new FileLogger();
        }
    }
    ~LoggerRule()
    {
        delete _consolLogger;
        delete _fileLogger;
    }

    void AddInLogger(Loggable* loggable)
    {
        if(_consolLogger)
        {
            _consolLogger->AddInLogger(loggable);
        }

        if(_fileLogger)
        {
            _fileLogger->AddInLogger(loggable);
        }
    }
private:
    ConsolLogger* _consolLogger = nullptr;
    FileLogger* _fileLogger = nullptr;
};
