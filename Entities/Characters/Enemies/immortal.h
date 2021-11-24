#pragma once

#include "enemy.h"

class Immortal : public Enemy
{
public:
    Immortal(Field* gameField, Cell* cell);
    virtual ~Immortal() = default;

    virtual void Move() override;
private:
    int _actualVertiaclDirection;

    void UpdateActualDirection();

};

