#pragma once

#include "Src/Entities/Characters/icharacter.h"
#include "Src/Containers/vector.h"
#include "Src/Entities/Characters/Enemies/EnemyMoveContoller/enemymovecontroller.h"

class Enemy : public Character
{
public:
    Enemy(Field* gameField, Cell* cell, int movingTime);
    Enemy(Field* gameField, Cell* cell, int movingTime, Mediator* _mediator);
    virtual ~Enemy();

    virtual void Die();

    virtual void Move(int variant) = 0;
    virtual int GetMovingTime();
    virtual int GetDirectionCount();

    virtual std::string LogOut() const override;

protected:
    Field* _gameField;
    Cell* _cell;

    int _directionCount;
    Vector<Vector<int>> _direction;

private:
    int _movingTime;

    EnemyMoveController* _enemyMoveController;
};
