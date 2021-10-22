#include "graphiccell.h"

GraphicCell::GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y, QPen pen, QBrush brush)
    : Cell(coord_x, coord_y)
    , _leftUpX(leftUpX)
    , _leftUpY(leftUpY)
    , _rightDownX(rightDownX)
    , _rightDownY(rightDownY)
    , _pen(pen)
    , _brush(brush)
{

}
void GraphicCell::DrawCell(QPainter *painter)
{
    painter->setPen(_pen);
    painter->setBrush(_brush);
    painter->drawRect(GetLeftUpX(), GetLeftUpY(), GetRightDownX(), GetRightDownY());
    if(_item != nullptr)
        _item->Draw(painter);
}

void GraphicCell::Moving(int x, int y, Cell*** cells)
{
    int coord_x = _coord_x + y;
    int coord_y = _coord_y + x;
    if(coord_x >= 0 && coord_y >= 0 && coord_x < 5 && coord_y < 8)
    {
        std::swap(cells[coord_x][coord_y]->_item, this->_item);
    }
}

GraphicCell::~GraphicCell()
{

}

GraphicCell::GraphicCell(const GraphicCell& other)
    : Cell(other._coord_x, other._coord_y)
    , _leftUpX(other._leftUpX)
    , _leftUpY(other._leftUpY)
    , _rightDownX(other._rightDownX)
    , _rightDownY(other._rightDownY)
    , _pen(other._pen)
    , _brush(other._brush)
{

}

GraphicCell& GraphicCell::operator=(const GraphicCell& other)
{
    _leftUpX = other._leftUpX;
    _leftUpY = other._leftUpY;
    _rightDownX = other._rightDownX;
    _rightDownY = other._rightDownY;

    _coord_x = other._coord_x;
    _coord_y = other._coord_y;

    _pen = other._pen;
    _brush = other._brush;

    return *this;
}

int GraphicCell::GetLeftUpX() const { return _leftUpX; }
int GraphicCell::GetLeftUpY() const { return _leftUpY; }
int GraphicCell::GetRightDownX() const { return _rightDownX; }
int GraphicCell::GetRightDownY() const { return _rightDownY; }

