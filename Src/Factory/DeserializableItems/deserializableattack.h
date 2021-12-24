#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Entities/Items/AttackItem/attackitem.h"

class DeserializableAttack : public DeserializableFactory
{
public:
    DeserializableAttack();
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory>* creator) override;
};
