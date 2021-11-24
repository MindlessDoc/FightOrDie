#pragma once

#include "Entities/Characters/icharacter.h"
#include "Containers/vector.h"
#include "Entities/Characters/Enemies/EnemyMoveContoller/enemymovecontroller.h"

class Enemy : public Character
{
public:
    Enemy(Field* gameField, Cell* cell, int movingTime, Mediator* _mediator);
    virtual ~Enemy();

    virtual void Move(int variant) = 0;
    virtual int GetMovingTime();
    virtual int GetDirectionCount();

protected:
    Field* _gameField;
    Cell* _cell;

    int _directionCount;
    Vector<Vector<int>> _direction;

private:
    //QTimer* _timerForMove;
    int _movingTime;

    EnemyMoveController* _enemyMoveController;
};
