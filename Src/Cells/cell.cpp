#include "cell.h"
#include "graphiccell.h"

#include "Src/Application/mediator.h"

Cell::Cell(int column, int row, Mediator* mediator)
    : _mediator(mediator)
    , _column(column)
    , _row(row)
{
    _entity = nullptr;
}

Cell::~Cell()
{
    delete _entity;
}

Cell::Cell(const Cell& other)
    : _column(other._column)
    , _row(other._row)
{
    _entity = other._entity; // Add copy constructor for concrete type of enemy
}

Cell& Cell::operator=(const Cell& other)
{
    _column = other._column;
    _row = other._row;

    _entity = other._entity; // Add copy constructor for concrete type of enemy

    return *this;
}

void Cell::Moving(Cell* swapCell)
{
    IEntity* additional = swapCell->GetEntity();
    swapCell->SetEntity(GetEntity());
    SetEntity(additional);

    _mediator->notifySwap(this, swapCell);
}

int Cell::GetColumn() const { return _column; }
int Cell::GetRow() const { return _row; }

IEntity* Cell::GetEntity() { return _entity; }
void Cell::SetEntity(IEntity *entity)
{
    _entity = entity;
}
