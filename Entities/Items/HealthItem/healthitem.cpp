#include "healthitem.h"
#include "Cells/cell.h"

HealthItem::HealthItem(Cell* cell, Mediator* mediator)
    : Item(cell, mediator)
{
    _cell->SetEntity(this);
}

HealthItem::HealthItem(Cell* cell)
    : Item(cell)
{
    _cell->SetEntity(this);
}

HealthItem::~HealthItem()
{
    _cell->SetEntity(nullptr);
    notify();
}

int HealthItem::GetHealthPointers() { return _healthPointers; }

std::string HealthItem::LogOut() const
{
    return "HealthItem: Have used!\n";
}
