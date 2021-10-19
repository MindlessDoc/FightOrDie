#include "graphiccell.h"

GraphicCell::GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y, QPen pen, QBrush brush)
    : Cell(leftUpX, leftUpY, rightDownX, rightDownY, coord_x, coord_y)
    , _pen(pen)
    , _brush(brush)
{
    connect(this, SIGNAL(Moving(int, int)), )
}
void GraphicCell::DrawCell(QPainter *painter)
{
    painter->setPen(_pen);
    painter->setBrush(_brush);
    painter->drawRect(GetLeftUpX(), GetLeftUpY(), GetRightDownX(), GetRightDownY());
    if(_item != nullptr)
        _item->Draw(painter);
}

void GraphicCell::Moving(int coord_x, int coord_y)
{
    Cell* additional = this - 8 * _coord_x - _coord_y;
    if(coord_x >= 0 && coord_y >= 0 && coord_x < 5 && coord_y < 8)
    {
        std::swap((additional + 8 * coord_x + coord_y)->_item, this->_item);
    }
}


GraphicCell::~GraphicCell()
{

}

GraphicCell::GraphicCell(const GraphicCell& other)
    : Cell(other._leftUpX, other._leftUpY, other._rightDownX, other._rightDownY, other._coord_x, other._coord_y)
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

