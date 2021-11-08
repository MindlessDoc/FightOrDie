#include "cell.h"
#include "graphiccell.h"

Cell::Cell(int column, int row)
    : _column(column)
    , _row(row)
{
    _item = nullptr;
}

Cell::~Cell()
{

}

Cell::Cell(const Cell& other)
    : _column(other._column)
    , _row(other._row)
{
    _item = other._item; // Add copy constructor for concrete type of enemy
}

Cell& Cell::operator=(const Cell& other)
{
    _column = other._column;
    _row = other._row;

    _item = other._item; // Add copy constructor for concrete type of enemy

    return *this;
}

int Cell::GetColumn() const { return _column; }
int Cell::GetRow() const { return _row; }
//IEntity* Cell::GetItem() { return _item; }
