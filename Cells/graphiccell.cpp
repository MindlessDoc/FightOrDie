#include "graphiccell.h"

GraphicCell::GraphicCell()
{

}

void Cell::DrawCell(QPainter *painter, const int leftUpX, const int leftUpY, const int rightDownX, const int rightDownY)
{
    painter->setPen(_pen);
    painter->setBrush(_brush);
    painter->drawRect(leftUpX, leftUpY, rightDownX, rightDownY);
}

