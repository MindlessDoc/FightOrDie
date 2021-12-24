#include "deserializableexit.h"

Cell* DeserializableExit::operator()(std::istream& is)
{
    int coord_x, coord_y;
    is >> coord_x >> coord_y;
    return new Exit(coord_x, coord_y);
}
