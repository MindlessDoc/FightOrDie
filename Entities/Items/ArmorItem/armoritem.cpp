#include "armoritem.h"
#include "Cells/cell.h"

ArmorItem::ArmorItem(Cell* cell)
    : Item(cell)
{
    _cell->SetEntity(this);
}

ArmorItem::~ArmorItem()
{
    _cell->SetEntity(nullptr);
}

int ArmorItem::GetArmorPointers() { return _armorPointers; }
