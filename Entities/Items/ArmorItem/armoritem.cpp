#include "armoritem.h"
#include "Cells/cell.h"

ArmorItem::ArmorItem(Cell* cell, Mediator* mediator)
    : Item(cell, mediator)
{
    _cell->SetEntity(this);
}

ArmorItem::~ArmorItem()
{
    _cell->SetEntity(nullptr);
    notify();
}

int ArmorItem::GetArmorPointers() { return _armorPointers; }

std::string ArmorItem::LogOut() const
{
    return "ArmorItem: Have used!\n";
}
