#pragma once

#include "Entities/ientity.h"
#include "Containers/vector.h"
#include <QKeyEvent>
#include <QObject>

class Cell;
class GraphicField;

class Player : public QObject, public IEntity
{
    Q_OBJECT
public:
    Player(GraphicField* gameField, GraphicCell* graphicCell);
    virtual void Draw(QPainter* painter) override;
public slots:
    void MovingItemCells(int x, int y);
private:
    Avatar _avatar;
    GraphicField* _gameField;
    GraphicCell* _graphicCell;
};
