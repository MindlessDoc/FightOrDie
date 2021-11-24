#pragma once

#include "Entities/Characters/icharacter.h"
#include "Containers/vector.h"

class Enemy : public ICharacter
{
public:
    Enemy(Field* gameField, Cell* cell, int movingTime, Mediator* _mediator);
    virtual ~Enemy();

    virtual void Move() = 0; // Think need 'Slot' or no    

protected:
    Field* _gameField;
    Cell* _cell;

    int _directionCount;
    Vector<Vector<int>> _direction;

private:
    //QTimer* _timerForMove;
    int _movingTime;


};
