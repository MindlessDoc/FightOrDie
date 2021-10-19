#include "graphiccell.h"

GraphicCell::GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, QPen pen, QBrush brush)
    : Cell(leftUpX, leftUpY, rightDownX, rightDownY)
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

GraphicCell::~GraphicCell()
{

}

GraphicCell::GraphicCell(const GraphicCell& other)
    : Cell(other._leftUpX, other._leftUpY, other._rightDownX, other._rightDownY)
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
    _pen = other._pen;
    _brush = other._brush;

    return *this;
}

