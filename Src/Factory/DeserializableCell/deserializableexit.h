#pragma once

#include "Src/Factory/deserializablefactory.h"
#include "Src/Cells/exit.h"

class DeserializableExit : public DeserializableFactory
{
public:
    DeserializableExit() = default;
    virtual Serializable* CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory*>* creator) override;
};

