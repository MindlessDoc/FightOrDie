#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Cells/way.h"

class DeserializableWay : public DeserializableFactory
{
public:
    DeserializableWay() = default;
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory>* creator) override;
};

