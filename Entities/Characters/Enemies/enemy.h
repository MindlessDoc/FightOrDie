#pragma once

#include "Entities/Characters/icharacter.h"

class Cell;
class GraphicField;

class Enemy : public QObject, public ICharacter
{
    Q_OBJECT
public:
    Enemy(GraphicField* gameField, GraphicCell* graphicCell);
    virtual void Draw(QPainter* painter) override;
//public slots:
//    void Move();
private:
    Avatar _avatar;
    GraphicField* _gameField;
    GraphicCell* _graphicCell;
};
