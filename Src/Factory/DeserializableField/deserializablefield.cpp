#include "deserializablefield.h"

Field* DeserializableField::operator()(std::istream &is)
{
    int heightInCells, widthInCells;
    is >> heightInCells >> widthInCells;
    return new Field(heightInCells, widthInCells);
}
