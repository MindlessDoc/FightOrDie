#pragma once

#include "Src/Cells/way.h"

class DeserializableWay
{
public:
    DeserializableWay() = default;
    Cell* operator()(std::istream& is);
};

