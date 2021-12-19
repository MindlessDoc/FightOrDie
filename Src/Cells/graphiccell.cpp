#include "graphiccell.h"
#include "Src/Entities/graphicentity.h"
#include "Src/Entities/EntityFactory/entityfactory.h"

GraphicCell::GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY,
                         Cell* cell, QString file)
    : _cell(cell)
    , _leftUpX(leftUpX)
    , _leftUpY(leftUpY)
    , _rightDownX(rightDownX)
    , _rightDownY(rightDownY)
    , _avatar(this, file)
{
    _graphicEntity = _entityFactory.CreateGraphicEntity(_cell->GetEntity(), this);
}
void GraphicCell::DrawCell(QPainter *painter)
{
    _avatar.Draw(this, painter);
    if(_graphicEntity != nullptr)
        _graphicEntity->Draw(this, painter);
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

void GraphicCell::EntitySwap(GraphicCell *graphicCell)
{
    std::swap(graphicCell->_graphicEntity, _graphicEntity);
}

int GraphicCell::GetLeftUpX() const { return _leftUpX; }
int GraphicCell::GetLeftUpY() const { return _leftUpY; }
int GraphicCell::GetRightDownX() const { return _rightDownX; }
int GraphicCell::GetRightDownY() const { return _rightDownY; }

GraphicEntity* GraphicCell::GetGraphicEntity()
{
    return _graphicEntity;
}

Cell* GraphicCell::GetCell()
{
    return _cell;
}

void GraphicCell::DeleteGraphicEntity()
{
    delete _graphicEntity;
    _graphicEntity = nullptr;
}


