#include "virus.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Virus::Virus(GraphicField* gameField, GraphicCell* graphicCell)
    : Enemy(gameField, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Virus.png", 1000)
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

void Virus::Move()
{
    int index = QRandomGenerator::global()->bounded(0, _directionCount);
    int newColumn = _graphicCell->GetColumn() + _direction[index][0];
    int newRow = _graphicCell->GetRow() + _direction[index][1];
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells())
    {
        if(((_gameField->GetCell(newColumn, newRow)->_entity && _gameField->GetCell(newColumn, newRow)->_entity->Type() == IEntity::PLAYER)
                || (!_gameField->GetCell(newColumn, newRow)->_entity))
                && static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->CanMoveIn())
        {
            if(_gameField->GetCell(newColumn, newRow)->_entity && _gameField->GetCell(newColumn, newRow)->_entity->Type() == IEntity::PLAYER)
            {
                delete _gameField->GetCell(newColumn, newRow)->_entity;
            }
            static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->Moving(_graphicCell);
            _graphicCell = static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow));
        }
    }
}

