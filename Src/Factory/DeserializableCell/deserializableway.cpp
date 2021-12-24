#include "deserializableway.h"

Cell* DeserializableWay::operator()(std::istream& is)
{
    int coord_x, coord_y;
    is >> coord_x >> coord_y;
    return new Way(coord_x, coord_y);
}
