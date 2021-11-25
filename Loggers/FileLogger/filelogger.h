#pragma once

#include "Loggers/logger.h"

class FileLogger : public Logger
{
public:
    FileLogger();

    virtual void Update(Loggable* loggable) override;
};
