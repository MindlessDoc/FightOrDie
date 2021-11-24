#pragma once

#include "Entities/Items/item.h"

class ArmorItem : public Item
{
public:
    ArmorItem(Cell* cell);
    virtual ~ArmorItem();

    int GetArmorPointers();
private:
    const int _armorPointers = 10;
};
