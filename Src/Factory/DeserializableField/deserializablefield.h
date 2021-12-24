#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Fields/field.h"

class DeserializableField : public DeserializableFactory
{
public:
    DeserializableField() = default;
    Field* operator()(std::istream& is);
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory*>* creator) override;
};
