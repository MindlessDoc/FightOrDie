#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Entities/Characters/Enemies/immortal.h"

class DeserializableImmortal : public DeserializableFactory
{
public:
    DeserializableImmortal() = default;
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory*>* creator) override;
};
