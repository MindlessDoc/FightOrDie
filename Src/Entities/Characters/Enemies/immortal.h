#pragma once

#include "enemy.h"

class Immortal : public Enemy
{
public:
    Immortal(Field* gameField, Cell* cell);
    Immortal(Field* gameField, Cell* cell, Mediator* mediator);
    virtual ~Immortal() = default;

    virtual void Move(int variant) override;

    virtual std::string LogOut() const override;

    virtual void Serialize(std::ostream& os) override;
private:
    int _actualVertiaclDirection;

    void UpdateActualDirection();

};

