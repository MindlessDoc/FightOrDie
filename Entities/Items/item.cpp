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
}
