#include "immortal.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Immortal::Immortal(GraphicField* gameField, GraphicCell* graphicCell)
    : Enemy(gameField, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Immortal.png", 1000)
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
    int newColumn = _graphicCell->GetColumn() + _actualVertiaclDirection;
    int newRow = _graphicCell->GetRow();
    if(!(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells()
            && static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->CanMoveIn()))
    {
        _actualVertiaclDirection *= -1;
    }
}

void Immortal::Move()
{
    UpdateActualDirection();
    int newColumn = _graphicCell->GetColumn() + _actualVertiaclDirection;
    int newRow = _graphicCell->GetRow();
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells()
        && static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->CanMoveIn())
    {
        if(_gameField->GetCell(newColumn, newRow)->_entity && _gameField->GetCell(newColumn, newRow)->_entity->Type() == IEntity::PLAYER)
        {
            delete static_cast<Player*>(_gameField->GetCell(newColumn, newRow)->_entity);
        }
        static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->Moving(_graphicCell);
        _graphicCell = static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow));
    }
}

int Immortal::Type()
{
    return IEntity::IMMORTAL;
}

