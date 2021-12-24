#pragma once

#include <string>
#include "Src/Serializable/serializable.h"

class Field;
class Cell;

class DeserializableFactory
{
public:
    DeserializableFactory();
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell) = 0;
};
