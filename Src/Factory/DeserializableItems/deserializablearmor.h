#pragma once

#include "Src/Factory/deserializablefactory.h"

class DeserializableArmor : public DeserializableFactory
{
public:
    DeserializableArmor();
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell) override;
};
