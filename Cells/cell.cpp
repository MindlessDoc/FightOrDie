#include "cell.h"
#include "graphiccell.h"

Cell::Cell(int column, int row)
    : _column(column)
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
    std::swap(swapCell->_entity, _entity); // Think how add checking
}

bool Cell::CanMoveIn()
{
    return false;
}

int Cell::GetEntityType(){ return (_entity) ? _entity->Type() : IEntity::NULLPTR; }

int Cell::GetColumn() const { return _column; }
int Cell::GetRow() const { return _row; }
