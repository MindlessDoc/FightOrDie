#pragma once

#include "Entities/Items/item.h"

class HealthItem : public Item
{
public:
    HealthItem(Cell* cell, Mediator* mediator);
    virtual ~HealthItem();

    int GetHealthPointers();
private:
    const int _healthPointers = 10;
};

