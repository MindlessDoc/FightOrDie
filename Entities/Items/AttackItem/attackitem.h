#pragma once

#include "Entities/Items/item.h"

class AttackItem : public Item
{
public:
    AttackItem(GraphicCell* graphicCell);
    virtual ~AttackItem();

    virtual void Draw(QPainter* painter) override;
    virtual int Type() override;

    int GetAttackPointers();
private:
    const int _attackPointers = 10;
};
