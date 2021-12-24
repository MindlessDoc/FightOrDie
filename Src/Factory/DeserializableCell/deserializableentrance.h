#pragma once

#include "Src/Cells/entrance.h"

class DeserializableEntrance
{
public:
    DeserializableEntrance() = default;
    Cell* operator()(std::istream& is);
};

