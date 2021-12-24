#pragma once

#include "Src/Fields/field.h"

class DeserializableField
{
public:
    DeserializableField() = default;
    Field* operator()(std::istream& is);
};
