#pragma once

#include "enemy.h"

class Virus : public Enemy
{
public:
    Virus(Field* gameField, Cell* cell);
    Virus(Field* gameField, Cell* cell, Mediator* mediator);
    virtual ~Virus() = default;

    virtual void Move(int variant) override;

    virtual std::string LogOut() const override;

    virtual void Serialize(std::ostream& os) override;
};

