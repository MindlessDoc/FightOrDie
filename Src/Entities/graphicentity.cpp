#include "graphicentity.h"

GraphicEntity::GraphicEntity(IEntity* entity, const GraphicCell* graphicCell, const QString filename)
    :_entity(entity)
    , _avatar(graphicCell, filename)
{

}
void GraphicEntity::Draw(GraphicCell *graphicCell, QPainter *painter)
{
   _avatar.Draw(graphicCell, painter);
}

GraphicEntity::~GraphicEntity()
{

}
