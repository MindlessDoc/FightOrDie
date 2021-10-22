#include "cell.h"
#include "graphiccell.h"

Cell::Cell(int coord_x, int coord_y)
    : _coord_x(coord_x)
    , _coord_y(coord_y)
{

}

Cell::~Cell()
{

}

Cell::Cell(const Cell& other)
    : _coord_x(other._coord_x)
    , _coord_y(other._coord_y)
{
    _item = other._item; // Add copy constructor for concrete type of enemy
}

Cell& Cell::operator=(const Cell& other)
{
    _coord_x = other._coord_x;
    _coord_y = other._coord_y;

    _item = other._item; // Add copy constructor for concrete type of enemy

    return *this;
}

int Cell::GetCoordX() const { return _coord_x; }
int Cell::GetCoordY() const { return _coord_y; }
