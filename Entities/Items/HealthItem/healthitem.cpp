#include "healthitem.h"
#include "Cells/graphiccell.h"

HealthItem::HealthItem(GraphicCell* graphicCell)
    : Item(graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/AidKit.png")
{
    _graphicCell->_entity = this;
}

HealthItem::~HealthItem()
{
    _graphicCell->_entity = nullptr;
}

void HealthItem::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

int HealthItem::Type()
{
    return IEntity::HEALTHITEM;
}

int HealthItem::GetHealthPointers() { return _healthPointers; }
