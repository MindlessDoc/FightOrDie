#pragma once

#include "Entities/ientity.h"
#include <QKeyEvent>
#include <QObject>

class Cell;

class Player : public QObject, public IEntity
{
    Q_OBJECT
public:
    Player(GraphicCell* _cell);
    virtual void Draw(QPainter* painter) override;
public slots:
    void MovingItemCells(int x, int y, Cell*** cells);
private:
    Avatar _avatar;
    GraphicCell* _graphicCell;
};
