#include "cell.h"

Cell::Cell(int leftUpX, int leftUpY, int rightDownX, int rightDownY)
    : _leftUpX(leftUpX)
    , _leftUpY(leftUpY)
    , _rightDownX(rightDownX)
    , _rightDownY(rightDownY)
{

}

Cell::~Cell()
{

}

int Cell::GetLeftUpX() { return _leftUpX; }
int Cell::GetLeftUpY() { return _leftUpY; }
int Cell::GetRightDownX() { return _rightDownX; }
int Cell::GetRightDownY() { return _rightDownY; }
