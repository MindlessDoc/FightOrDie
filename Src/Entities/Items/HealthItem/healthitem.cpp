#include "healthitem.h"
#include "Src/Cells/cell.h"

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

void HealthItem::Serialize(std::ostream &os)
{
    os << typeid (HealthItem).name() << std::endl;
}
