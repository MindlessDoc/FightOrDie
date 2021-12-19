#pragma once

#include <iostream>
#include <fstream>
#include "Src/Loggers/logger.h"

class FileLogger : public Logger
{
public:
    FileLogger(std::string filename = "C:/QtProjects/OOP/FightOrDie/logout.txt");
    virtual ~FileLogger();

    virtual void Update(Loggable* loggable) override;
private:
    std::ofstream _out;
    std::string _filename;
};
