#include "healthitem.h"
#include "Cells/cell.h"

HealthItem::HealthItem(Cell* cell, Mediator* mediator)
    : Item(cell, mediator)
{
    _cell->SetEntity(this);
}

HealthItem::~HealthItem()
{
    _cell->SetEntity(nullptr);
}

int HealthItem::GetHealthPointers() { return _healthPointers; }
