#pragma once

#include "Src/Loggers/logger.h"

class ConsolLogger : public Logger
{
public:
    ConsolLogger();

    virtual void Update(Loggable* loggable) override;
};

