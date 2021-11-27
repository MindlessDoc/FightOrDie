#pragma once

#include "Rules/rule.h"
#include "Loggers/ConsolLogger/consollogger.h"
#include "Loggers/FileLogger/filelogger.h"

#include "Loggable/loggable.h"

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
