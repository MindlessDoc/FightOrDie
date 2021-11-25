#pragma once

#include "Entities/Items/item.h"

class HealthItem : public Item
{
public:
    HealthItem(Cell* cell, Mediator* mediator);
    virtual ~HealthItem();

    int GetHealthPointers();

    std::string LogOut() const override;

private:
    const int _healthPointers = 10;
};

