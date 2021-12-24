#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Entities/Characters/Enemies/trojan.h"

class DeserializableTrojan : public DeserializableFactory
{
public:
    DeserializableTrojan();
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell) override;
};
