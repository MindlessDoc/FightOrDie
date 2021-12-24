#pragma once

#include "Src/Cells/exit.h"

class DeserializableExit
{
public:
    DeserializableExit() = default;
    Cell* operator()(std::istream& is);
};

