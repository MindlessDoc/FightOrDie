#include "immortal.h"
#include "Src/Cells/cell.h"
#include "Src/Fields/field.h"

Immortal::Immortal(Field* gameField, Cell* cell)
    : Enemy(gameField, cell, 5000)
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

Immortal::Immortal(Field* gameField, Cell* cell, Mediator* mediator)
    : Enemy(gameField, cell, 5000, mediator)
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
    if(!(_gameField->CheckOnInclusion(newColumn, newRow))
            || !(_gameField->GetCell(newColumn, newRow)->CanMoveIn(_cell->GetEntity()))
            || (_gameField->GetCell(newColumn, newRow)->GetEntity() && typeid(*(_gameField->GetCell(newColumn, newRow)->GetEntity())) != typeid(Player)))
    {
        _actualVertiaclDirection *= -1;
    }
}

void Immortal::Move(int variant)
{
    UpdateActualDirection();
    int newColumn = _cell->GetColumn() + _actualVertiaclDirection;
    int newRow = _cell->GetRow();
    if(_gameField->CheckOnInclusion(newColumn, newRow)
        && _gameField->GetCell(newColumn, newRow)->CanMoveIn(_cell->GetEntity()))
    {
        if(!_gameField->GetCell(newColumn, newRow)->GetEntity())
        {
            _gameField->GetCell(newColumn, newRow)->Moving(_cell);
            _cell = _gameField->GetCell(newColumn, newRow);
        }
        else if(_gameField->GetCell(newColumn, newRow)->GetEntity() && typeid(*(_gameField->GetCell(newColumn, newRow)->GetEntity())) == typeid(Player))
        {
            delete _gameField->GetCell(newColumn, newRow)->GetEntity(); // CHEKING
            _gameField->GetCell(newColumn, newRow)->Moving(_cell);
            _cell = _gameField->GetCell(newColumn, newRow);
        }
    }
    notify();
}

std::string Immortal::LogOut() const
{
    return  "Immortal info:\nCoordinates: column = " + std::to_string(_cell->GetColumn())+
            " row = " + std::to_string(_cell->GetRow()) + "\n";
}
