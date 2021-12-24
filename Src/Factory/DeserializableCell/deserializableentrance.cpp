#include "deserializableentrance.h"

Cell* DeserializableEntrance::operator()(std::istream& is)
{
    int coord_x, coord_y;
    is >> coord_x >> coord_y;
    return new Entrance(coord_x, coord_y);
}
