#pragma once

#include "Entities/Items/item.h"

class AttackItem : public Item
{
public:
    AttackItem(Cell* cell, Mediator* mediator);
    virtual ~AttackItem();

    int GetAttackPointers();
private:
    const int _attackPointers = 10;
};
