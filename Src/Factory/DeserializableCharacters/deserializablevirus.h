#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Entities/Characters/Enemies/virus.h"

class DeserializableVirus : public DeserializableFactory
{
public:
    DeserializableVirus();
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory>* creator) override;
};
