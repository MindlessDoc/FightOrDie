#include "graphiccell.h"

GraphicCell::GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY,
                         Cell* cell, GraphicIEntity* graphicEntity,  QString file)
    : _cell(cell)
    , _graphicEntity(graphicEntity)
    , _leftUpX(leftUpX)
    , _leftUpY(leftUpY)
    , _rightDownX(rightDownX)
    , _rightDownY(rightDownY)
    , _avatar(this, file)
{

}
void GraphicCell::DrawCell(QPainter *painter)
{
    _avatar.Draw(this, painter);
    if(_cell->GetEntity() != nullptr)
        _cell->GetEntity()->Draw(painter);
}

void GraphicCell::UpdateAvatar(QString filename)
{
    _avatar.UpdatePicture(filename);
}


GraphicCell::GraphicCell(const GraphicCell& other)
    : _cell(other._cell)
    , _leftUpX(other._leftUpX)
    , _leftUpY(other._leftUpY)
    , _rightDownX(other._rightDownX)
    , _rightDownY(other._rightDownY)
    , _avatar(this, other._avatar.GetFilename())
{

}

GraphicCell& GraphicCell::operator=(const GraphicCell& other)
{
    _cell = other._cell;
    _leftUpX = other._leftUpX;
    _leftUpY = other._leftUpY;
    _rightDownX = other._rightDownX;
    _rightDownY = other._rightDownY;

    return *this;
}

int GraphicCell::GetLeftUpX() const { return _leftUpX; }
int GraphicCell::GetLeftUpY() const { return _leftUpY; }
int GraphicCell::GetRightDownX() const { return _rightDownX; }
int GraphicCell::GetRightDownY() const { return _rightDownY; }

