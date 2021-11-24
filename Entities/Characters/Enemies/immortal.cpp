#include "immortal.h"
#include "Cells/cell.h"
#include "Fields/field.h"

Immortal::Immortal(Field* gameField, Cell* cell, Mediator* mediator)
    : Enemy(gameField, cell, 1000, mediator)
{
    //Think how to reduce
    _directionCount = 2;
    _direction.resize(_directionCount);
    for(int i = 0; i < _directionCount; i++)
    {
        _direction[i].resize(2);
    }

//    _direction[0][0] = -1; _direction[0][1] = 0;
//    _direction[1][0] = 1; _direction[1][1] = 0;

    _actualVertiaclDirection = 1;
}

void Immortal::UpdateActualDirection()
{
    int newColumn = _cell->GetColumn() + _actualVertiaclDirection;
    int newRow = _cell->GetRow();
    if(!(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells()
            && _gameField->GetCell(newColumn, newRow)->CanMoveIn(_cell->GetEntity())))
    {
        _actualVertiaclDirection *= -1;
    }
}

void Immortal::Move()
{
    UpdateActualDirection();
    int newColumn = _cell->GetColumn() + _actualVertiaclDirection;
    int newRow = _cell->GetRow();
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells()
        && _gameField->GetCell(newColumn, newRow)->CanMoveIn(_cell->GetEntity()))
    {
        if(_gameField->GetCell(newColumn, newRow)->GetEntity() && typeid(_gameField->GetCell(newColumn, newRow)->GetEntity()) == typeid(Player))
        {
            delete _gameField->GetCell(newColumn, newRow)->GetEntity(); // CHEKING
        }
        _gameField->GetCell(newColumn, newRow)->Moving(_cell);
        _cell = _gameField->GetCell(newColumn, newRow);
    }
}
