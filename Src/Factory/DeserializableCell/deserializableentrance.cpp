#include "deserializableentrance.h"

Serializable* DeserializableEntrance::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    int coord_x, coord_y;
    is >> coord_x >> coord_y;
    return new Entrance(coord_x, coord_y);
}
