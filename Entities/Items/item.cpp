#include "item.h"
#include "Cells/cell.h"

Item::Item(Cell* cell, Mediator* mediator)
    : _cell(cell)
    , _mediator(mediator)
{

}

Item::~Item()
{
    _cell->SetEntity(nullptr);
    _mediator->notifyDeleteEntity(_cell->GetColumn(), _cell->GetRow());
}

std::string Item::LogOut() const
{
    return "Have used!";
}
