#include "cell.h"
#include "graphiccell.h"

Cell::Cell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y)
    : _leftUpX(leftUpX)
    , _leftUpY(leftUpY)
    , _rightDownX(rightDownX)
    , _rightDownY(rightDownY)
    , _coord_x(coord_x)
    , _coord_y(coord_y)
{

}

Cell::~Cell()
{

}

Cell::Cell(const Cell& other)
    : _leftUpX(other._leftUpX)
    , _leftUpY(other._leftUpY)
    , _rightDownX(other._rightDownX)
    , _rightDownY(other._rightDownY)
    , _coord_x(other._coord_x)
    , _coord_y(other._coord_y)
{
    _item = other._item; // Add copy constructor for concrete type of enemy
}

Cell& Cell::operator=(const Cell& other)
{
    _leftUpX = other._leftUpX;
    _leftUpY = other._leftUpY;
    _rightDownX = other._rightDownX;
    _rightDownY = other._rightDownY;
    _coord_x = other._coord_x;
    _coord_y = other._coord_y;

    _item = other._item; // Add copy constructor for concrete type of enemy

    return *this;
}

int Cell::GetLeftUpX() const { return _leftUpX; }
int Cell::GetLeftUpY() const { return _leftUpY; }
int Cell::GetRightDownX() const { return _rightDownX; }
int Cell::GetRightDownY() const { return _rightDownY; }

int Cell::GetCoordX() const { return _coord_x; }
int Cell::GetCoordY() const { return _coord_y; }
