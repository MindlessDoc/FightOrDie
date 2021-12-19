#pragma once

#include "Src/Entities/Items/item.h"

class ArmorItem : public Item
{
public:
    ArmorItem(Cell* cell);
    ArmorItem(Cell* cell, Mediator* mediator);
    virtual ~ArmorItem();

    int GetArmorPointers();

    std::string LogOut() const override;

private:
    const int _armorPointers = 10;
};
