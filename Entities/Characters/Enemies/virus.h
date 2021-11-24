#pragma once

#include "enemy.h"

class Virus : public Enemy
{
public:
    Virus(Field* gameField, Cell* cell, Mediator* mediator);
    virtual ~Virus() = default;

    virtual void Move(int variant) override;
};

