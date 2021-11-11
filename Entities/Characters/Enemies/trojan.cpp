#include "trojan.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Trojan::Trojan(GraphicField* gameField, GraphicCell* graphicCell)
    : Enemy(gameField, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Enemy.png", 1000)
{
    //Think how to reduce
    _directionCount = 8;
    _direction.resize(_directionCount);
    for(int i = 0; i < _directionCount; i++)
    {
        _direction[i].resize(2);
    }

    _direction[0][0] = -1; _direction[0][1] = -2;
    _direction[1][0] = 1; _direction[1][1] = -2;
    _direction[2][0] = -2; _direction[2][1] = -1;
    _direction[3][0] = -2; _direction[3][1] = 1;
    _direction[4][0] = -1; _direction[4][1] = 2;
    _direction[5][0] = 1; _direction[5][1] = 2;
    _direction[6][0] = 2; _direction[6][1] = -1;
    _direction[7][0] = 2; _direction[7][1] = 1;
}

void Trojan::Move()
{
    int index = QRandomGenerator::global()->bounded(0, _directionCount);
    int newColumn = _graphicCell->GetColumn() + _direction[index][0];
    int newRow = _graphicCell->GetRow() + _direction[index][1];
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells()
            && static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->CanMoveIn())
    {
        if(_gameField->GetCell(newColumn, newRow)->GetEntityType() == IEntity::PLAYER)
        {
            delete static_cast<Player*>(_gameField->GetCell(newColumn, newRow)->_entity);
            static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->Moving(_graphicCell);
            _graphicCell = static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow));
        }
        else if(_gameField->GetCell(newColumn, newRow)->GetEntityType() == IEntity::NULLPTR)
        {
            static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->Moving(_graphicCell);
            _graphicCell = static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow));
        }
    }
}
