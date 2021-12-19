#pragma once

#include "ientity.h"
#include <QPainter>
#include "Src/Avatar/avatar.h"

class GraphicEntity
{
public:
    GraphicEntity(IEntity* _entity, const GraphicCell* graphicCell, const QString filename);
    virtual ~GraphicEntity();
    virtual void Draw(GraphicCell* graphicCell, QPainter* painter);
private:
    IEntity* _entity;
    Avatar _avatar;
};
