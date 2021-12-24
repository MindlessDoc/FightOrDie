#pragma once

#include "Src/Serializable/serializable.h"
#include <map>

class Field;
class Cell;

class DeserializableFactory
{
public:
    DeserializableFactory();
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory*>* creator) = 0;
};
