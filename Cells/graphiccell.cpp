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
}

GraphicCell::~GraphicCell()
{

}

