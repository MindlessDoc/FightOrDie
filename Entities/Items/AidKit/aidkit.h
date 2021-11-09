#pragma once

#include "Entities/Items/item.h"

class AidKit : public Item
{
public:
    AidKit(GraphicCell* graphicCell);

    virtual void Draw(QPainter* painter) override;
    virtual int Type() override;

    int GetHealthPointers();
private:
    const int _healthPointers = 10;

};

