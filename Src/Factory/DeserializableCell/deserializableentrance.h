#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Cells/entrance.h"

class DeserializableEntrance : public DeserializableFactory
{
public:
    DeserializableEntrance() = default;
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory>* creator) override;
};

