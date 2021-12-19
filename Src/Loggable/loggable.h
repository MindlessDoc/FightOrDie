#pragma once

#include <vector>
#include "Src/Loggers/logger.h"
#include <iostream>
#include <string>
#include <fstream>

class Loggable
{
public:
    Loggable();
    virtual ~Loggable();

    void notify();
    void AddLogger(Logger* logger);

    virtual std::string LogOut() const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Loggable &obj);

private:
    std::vector<Logger*> _loggers;
};
