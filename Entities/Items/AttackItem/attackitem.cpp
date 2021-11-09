#include "attackitem.h"
#include "Cells/graphiccell.h"

AttackItem::AttackItem(GraphicCell* graphicCell)
    : Item(graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/ZeroGun.png")
{
    _graphicCell->_entity = this;
}

AttackItem::~AttackItem()
{
    _graphicCell->_entity = nullptr;
}

void AttackItem::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

int AttackItem::Type()
{
    return IEntity::ATTACKITEM;
}

int AttackItem::GetAttackPointers() { return _attackPointers; }
