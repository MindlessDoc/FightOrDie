#pragma once

#include "Entities/ientity.h"

class Item : public IEntity
{
public:
    Item(GraphicCell* graphicCell, QString filename);
    virtual ~Item();
protected:
    Avatar _avatar;
    GraphicCell* _graphicCell;
};

