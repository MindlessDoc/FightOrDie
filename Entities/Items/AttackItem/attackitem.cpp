#include "attackitem.h"
#include "Cells/cell.h"

AttackItem::AttackItem(Cell* cell)
    : Item(cell)
{
    _cell->SetEntity(this);
}

AttackItem::~AttackItem()
{
    _cell->SetEntity(nullptr);
}

int AttackItem::GetAttackPointers() { return _attackPointers; }
