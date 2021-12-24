#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Entities/Items/HealthItem/healthitem.h"

class DeserializableHealth : public DeserializableFactory
{
public:
    DeserializableHealth() = default;
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory*>* creator) override;
};
