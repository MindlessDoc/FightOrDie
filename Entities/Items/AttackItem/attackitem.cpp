#include "attackitem.h"
#include "Cells/cell.h"

AttackItem::AttackItem(Cell* cell, Mediator* mediator)
    : Item(cell, mediator)
{
    _cell->SetEntity(this);
}

AttackItem::~AttackItem()
{
    _cell->SetEntity(nullptr);
}

int AttackItem::GetAttackPointers() { return _attackPointers; }
