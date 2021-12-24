#include "enemy.h"
#include "Src/Cells/cell.h"
#include "Src/Fields/graphicfield.h"
#include "EnemyMoveContoller/qtenemymovecontroller.h"
#include "Src/Application/mediator.h"

Enemy::Enemy(Field* gameField, Cell* cell, int movingTime)
    : _gameField(gameField)
    , _cell(cell)
    , _movingTime(movingTime)
{
    _cell->SetEntity(this);

    _enemyMoveController = new QtEnemyMoveController(this);
}

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
    delete _enemyMoveController;
}

void Enemy::Die()
{
    _mediator->notifyDeleteEntity(_cell->GetColumn(), _cell->GetRow());
    delete this;
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

