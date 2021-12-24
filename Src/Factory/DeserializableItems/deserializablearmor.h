#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Entities/Items/ArmorItem/armoritem.h"

class DeserializableArmor : public DeserializableFactory
{
public:
    DeserializableArmor();
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell) override;
};
