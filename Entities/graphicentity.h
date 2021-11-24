#pragma once

#include "ientity.h"
#include <QPainter>
#include "Avatar/avatar.h"
#include "Cells/graphiccell.h"

class GraphicEntity
{
public:
    GraphicEntity(IEntity* entity, const GraphicCell* graphicCell, const QString filename);
    virtual void Draw(GraphicCell* graphicCell, QPainter* painter);
private:
    IEntity* _entity;
    Avatar _avatar;
};
