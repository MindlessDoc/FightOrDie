#pragma once

#include "Src/Entities/Items/item.h"

class AttackItem : public Item
{
public:
    AttackItem(Cell* cell);
    AttackItem(Cell* cell, Mediator* mediator);
    virtual ~AttackItem();

    int GetAttackPointers();

    std::string LogOut() const override;

    virtual void Serialize(std::ostream& os) override;

private:
    const int _attackPointers = 10;
};
