#include "enemy.h"
#include "Cells/cell.h"
#include "Fields/graphicfield.h"
#include "EnemyMoveContoller/qtenemymovecontroller.h"
#include "Application/mediator.h"

Enemy::Enemy(Field* gameField, Cell* cell, int movingTime, Mediator* mediator)
    : _gameField(gameField)
    , _cell(cell)
    , _movingTime(movingTime)
{
    _cell->SetEntity(this);
    _mediator = mediator;

    _enemyMoveController = new QtEnemyMoveController(this);
}

Enemy::~Enemy()
{
    _cell->SetEntity(nullptr);
    _mediator->notifyDeleteEntity(_cell->GetColumn(), _cell->GetRow());

    delete _enemyMoveController;
}

int Enemy::GetMovingTime()
{
    return _movingTime;
}

int Enemy::GetDirectionCount()
{
    return _directionCount;
}

std::string Enemy::LogOut() const
{
    return  "Coordinates: column = " + std::to_string(_cell->GetColumn())+
            " row = " + std::to_string(_cell->GetRow()) + "\n";
}
