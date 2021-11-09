#include "graphiccell.h"

GraphicCell::GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y, QPen pen, QBrush brush,
                         QString file)
    : Cell(coord_x, coord_y)
    , _leftUpX(leftUpX)
    , _leftUpY(leftUpY)
    , _rightDownX(rightDownX)
    , _rightDownY(rightDownY)
    , _pen(pen)
    , _brush(brush)
    , _avatar(this, file)
{

}
void GraphicCell::DrawCell(QPainter *painter)
{
    painter->setPen(_pen);
    painter->setBrush(_brush);
    painter->drawRect(GetLeftUpX(), GetLeftUpY(), GetRightDownX(), GetRightDownY());
    _avatar.Draw(this, painter);
    if(_entity != nullptr)
        _entity->Draw(painter);
}

void GraphicCell::Moving(GraphicCell* swapCell)
{
    std::swap(swapCell->_entity, _entity); // Think how add checking
}

GraphicCell::~GraphicCell()
{

}

GraphicCell::GraphicCell(const GraphicCell& other)
    : Cell(other._column, other._row)
    , _leftUpX(other._leftUpX)
    , _leftUpY(other._leftUpY)
    , _rightDownX(other._rightDownX)
    , _rightDownY(other._rightDownY)
    , _pen(other._pen)
    , _brush(other._brush)
    , _avatar(this, other._avatar.GetFilename())
{

}

GraphicCell& GraphicCell::operator=(const GraphicCell& other)
{
    _leftUpX = other._leftUpX;
    _leftUpY = other._leftUpY;
    _rightDownX = other._rightDownX;
    _rightDownY = other._rightDownY;

    _column = other._column;
    _row = other._row;

    _pen = other._pen;
    _brush = other._brush;

    return *this;
}

int GraphicCell::GetLeftUpX() const { return _leftUpX; }
int GraphicCell::GetLeftUpY() const { return _leftUpY; }
int GraphicCell::GetRightDownX() const { return _rightDownX; }
int GraphicCell::GetRightDownY() const { return _rightDownY; }

