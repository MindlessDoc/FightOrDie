#pragma once

#include "Src/Entities/Items/item.h"

class HealthItem : public Item
{
public:
    HealthItem(Cell* cell);
    HealthItem(Cell* cell, Mediator* mediator);
    virtual ~HealthItem();

    int GetHealthPointers();

    std::string LogOut() const override;

    virtual void Serialize(std::ostream& os) override;

private:
    const int _healthPointers = 10;
};

