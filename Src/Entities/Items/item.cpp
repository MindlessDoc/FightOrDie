#include "item.h"
#include "Src/Cells/cell.h"

#include "Src/Application/mediator.h"

Item::Item(Cell* cell, Mediator* mediator)
    : _cell(cell)
    , _mediator(mediator)
{

}

Item::Item(Cell* cell)
    : _cell(cell)
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

void Item::SetMediator(Mediator* mediator) { _mediator = mediator; }
