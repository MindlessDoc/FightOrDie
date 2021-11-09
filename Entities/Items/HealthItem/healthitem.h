#pragma once

#include "Entities/Items/item.h"

class HealthItem : public Item
{
public:
    HealthItem(GraphicCell* graphicCell);
    virtual ~HealthItem();

    virtual void Draw(QPainter* painter) override;
    virtual int Type() override;

    int GetHealthPointers();
private:
    const int _healthPointers = 10;
};

