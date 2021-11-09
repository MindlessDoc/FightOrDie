#include "armoritem.h"
#include "Cells/graphiccell.h"

ArmorItem::ArmorItem(GraphicCell* graphicCell)
    : Item(graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Antivirus.png")
{
    _graphicCell->_entity = this;
}

ArmorItem::~ArmorItem()
{
    _graphicCell->_entity = nullptr;
}

void ArmorItem::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

int ArmorItem::Type()
{
    return IEntity::ARMORITEM;
}

int ArmorItem::GetArmorPointers() { return _armorPointers; }
