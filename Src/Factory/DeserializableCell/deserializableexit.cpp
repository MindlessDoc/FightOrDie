#include "deserializableexit.h"

Serializable* DeserializableExit::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    int coord_x, coord_y;
    is >> coord_x >> coord_y;
    return new Exit(coord_x, coord_y);
}
