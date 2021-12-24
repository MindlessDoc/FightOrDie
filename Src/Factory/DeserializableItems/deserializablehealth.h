#pragma once

#include "Src/Factory/deserializablefactory.h"

class DeserializableHealth : public DeserializableFactory
{
public:
    DeserializableHealth();
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell) override;
};
