#include "deserializablefield.h"

Serializable* DeserializableField::CreateObject(std::istream& is, Field* field, Cell* cell,
                                       std::map<std::string, DeserializableFactory*>* creator)
{
    int heightInCells, widthInCells;
    is >> heightInCells >> widthInCells;
    return new Field(heightInCells, widthInCells);
}
