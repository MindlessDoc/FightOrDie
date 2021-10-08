#include "cell.h"

Cell::Cell(int state)
{
    _state = state;

    _pen = QPen(Qt::black, 1.0);

    switch(_state)
    {
    case ENTRANCE:
        _brush = QBrush(Qt::yellow);
        break;
    case EXIT:
        _brush = QBrush(Qt::green);
        break;
    case BARRIER:
        _brush = QBrush(Qt::red);
        break;
    case WAY:
        _brush = QBrush(Qt::gray);
        break;
    }
}

Cell::Cell()
{

}

Cell::~Cell()
{

}

void Cell::DrawCell(QPainter *painter, int leftUpX, int leftUpY, int rightDownX, int rightDownY)
{
    painter->setPen(_pen);
    painter->setBrush(_brush);
    painter->drawRect(leftUpX, leftUpY, rightDownX, rightDownY);
}

int Cell::GetHeight()
{
    return _height;
}
int Cell::GetWidth()
{
    return _width;
}

