#pragma once

#include "Entities/ientity.h"

class Item : public IEntity
{
public:
    Item(GraphicCell* graphicCell, QString filename);
protected:
    Avatar _avatar;
    GraphicCell* _graphicCell;
};

