#include "virus.h"
#include "Cells/cell.h"
#include "Fields/field.h"

Virus::Virus(Field* gameField, Cell* cell, Mediator* mediator)
    : Enemy(gameField, cell, 1000, mediator)
{
    //Think how to reduce
    _directionCount = 4;
    _direction.resize(_directionCount);
    for(int i = 0; i < _directionCount; i++)
    {
        _direction[i].resize(2);
    }

    _direction[0][0] = -1; _direction[0][1] = 0;
    _direction[1][0] = 1; _direction[1][1] = 0;
    _direction[2][0] = 0; _direction[2][1] = -1;
    _direction[3][0] = 0; _direction[3][1] = 1;
}

void Virus::Move(int variant)
{
    //CHANGE!!!!!
    int newColumn = _cell->GetColumn() + _direction[variant][0];
    int newRow = _cell->GetRow() + _direction[variant][1];
    if(_gameField->CheckOnInclusion(newColumn, newRow))
    {
        if(((_gameField->GetCell(newColumn, newRow)->GetEntity() && typeid(*(_gameField->GetCell(newColumn, newRow)->GetEntity())) == typeid(Player))
                || (!_gameField->GetCell(newColumn, newRow)->GetEntity()))
                && _gameField->GetCell(newColumn, newRow)->CanMoveIn(_cell->GetEntity()))
        {
            if(_gameField->GetCell(newColumn, newRow)->GetEntity() && typeid(*(_gameField->GetCell(newColumn, newRow)->GetEntity())) == typeid(Player))
            {
                //CHEKING!!!
                delete _gameField->GetCell(newColumn, newRow)->GetEntity();
            }
            _gameField->GetCell(newColumn, newRow)->Moving(_cell);
            _cell = _gameField->GetCell(newColumn, newRow);
        }
    }
}

