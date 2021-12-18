#include "attackitem.h"
#include "Cells/cell.h"

AttackItem::AttackItem(Cell* cell, Mediator* mediator)
    : Item(cell, mediator)
{
    _cell->SetEntity(this);
}

AttackItem::AttackItem(Cell* cell)
    : Item(cell)
{
    _cell->SetEntity(this);
}


AttackItem::~AttackItem()
{
    _cell->SetEntity(nullptr);
    notify();
}

int AttackItem::GetAttackPointers() { return _attackPointers; }

std::string AttackItem::LogOut() const
{
    return "AttackItem: Have used!\n";
}
