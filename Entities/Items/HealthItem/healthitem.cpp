#include "healthitem.h"
#include "Cells/cell.h"

int HealthItem::GetHealthPointers() { return _healthPointers; }

HealthItem::HealthItem(Cell* cell)
    : Item(cell)
{
    _cell->SetEntity(this);
}

HealthItem::~HealthItem()
{
    _cell->SetEntity(nullptr);
}

int HealthItem::GetHealthPointers() { return _healthPointers; }
