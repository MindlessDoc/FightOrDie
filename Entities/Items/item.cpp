#include "item.h"
#include "Cells/cell.h"

Item::Item(Cell* cell)
    : _cell(cell)
{

}

Item::~Item()
{
    _cell->SetEntity(nullptr);
}
