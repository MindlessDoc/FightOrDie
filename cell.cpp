#include "cell.h"

Cell::Cell(bool state)
{
    _state = state;
}

int Cell::GetHeight()
{
    return _height;
}
int Cell::GetWidth()
{
    return _width;
}
