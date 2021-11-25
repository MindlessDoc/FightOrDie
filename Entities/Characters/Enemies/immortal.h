#pragma once

#include "enemy.h"

class Immortal : public Enemy
{
public:
    Immortal(Field* gameField, Cell* cell, Mediator* mediator);
    virtual ~Immortal() = default;

    virtual void Move(int variant) override;

    virtual std::string LogOut() const override;
private:
    int _actualVertiaclDirection;

    void UpdateActualDirection();

};

