#pragma once

#include "Entities/Items/item.h"

class ArmorItem : public Item
{
public:
    ArmorItem(GraphicCell* graphicCell);
    virtual ~ArmorItem();

    virtual void Draw(QPainter* painter) override;
    virtual int Type() override;

    int GetArmorPointers();
private:
    const int _armorPointers = 10;
};
