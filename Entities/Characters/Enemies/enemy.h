#pragma once

#include "Entities/Characters/icharacter.h"
#include "Containers/vector.h"

class GraphicField;

class Enemy : public ICharacter
{
public:
    Enemy(GraphicField* gameField, GraphicCell* graphicCell, QString filename, int movingTime);
    virtual ~Enemy();

    virtual void Draw(QPainter* painter) override;
    virtual int Type() override;
    virtual void Move() = 0; // Think need 'Slot' or no    

protected:
    GraphicField* _gameField;
    GraphicCell* _graphicCell;

    int _directionCount;
    Vector<Vector<int>> _direction;

private:

    QTimer* _timerForMove;
    int _movingTime;


};
