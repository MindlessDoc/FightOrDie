#pragma once

#include "enemy.h"

class Virus : public Enemy
{
public:
    Virus(Field* gameField, Cell* cell);
    virtual ~Virus() = default;

    virtual void Move() override;
};

