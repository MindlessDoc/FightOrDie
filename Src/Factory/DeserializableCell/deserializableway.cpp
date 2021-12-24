#include "deserializableway.h"

Serializable* DeserializableWay::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    int coord_x, coord_y;
    is >> coord_x >> coord_y;
    return new Way(coord_x, coord_y);
}
