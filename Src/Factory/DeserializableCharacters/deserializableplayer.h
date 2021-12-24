#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Entities/Characters/Player/player.h"

class DeserializablePlayer : public DeserializableFactory
{
public:
    DeserializablePlayer();
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory*>* creator) override;
};
