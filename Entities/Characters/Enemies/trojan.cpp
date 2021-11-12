#include "trojan.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Trojan::Trojan(GraphicField* gameField, GraphicCell* graphicCell)
    : Enemy(gameField, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Enemy.png", 3000)
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

    SetNextStep();
}

void Trojan::SetNextStep()
{
    Vector<Vector<int>> canMove;
    for(int i = 0; i < _directionCount; i++)
    {
        int newColumn = _graphicCell->GetColumn() + _direction[i][0];
        int newRow = _graphicCell->GetRow() + _direction[i][1];
        if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells()
                && newRow < _gameField->GetWidthInCells()
             && static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->CanMoveIn())
        {
            canMove.push_back(_direction[i]);
        }
    }

    if(!canMove.empty())
    {
        int index = QRandomGenerator::global()->bounded(0, int(canMove.size()));
        _nextStep = static_cast<GraphicCell*>(_gameField->GetCell(_graphicCell->GetColumn() + canMove[index][0],
                                    _graphicCell->GetRow() + canMove[index][1]));
        _nextStep->UpdateAvatar("C:/QtProjects/OOP/FightOrDie/Src/NextStepTrojan.png");
    }
    else
    {
        _nextStep = nullptr;
    }
}

void Trojan::Move()
{
    if(_nextStep)
    {
        if(_nextStep->GetEntityType() == IEntity::PLAYER)
        {
            delete static_cast<Player*>(_nextStep->_entity);
        }
        _nextStep->Moving(_graphicCell);
        _graphicCell = _nextStep;
        _nextStep->UpdateAvatar("C:/QtProjects/OOP/FightOrDie/Src/Way.png");
    }
    SetNextStep();
}
