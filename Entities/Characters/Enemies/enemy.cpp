#include "enemy.h"
#include "Cells/cell.h"
#include "Fields/graphicfield.h"

Enemy::Enemy(Field* gameField, Cell* cell, int movingTime, Mediator* mediator)
    : _gameField(gameField)
    , _cell(cell)
    , _movingTime(movingTime)
{
    _cell->SetEntity(this);
    _mediator = mediator;
    //_timerForMove = new QTimer();
    //connect(_timerForMove, &QTimer::timeout, this, &Enemy::Move);
    //_timerForMove->start(_movingTime);
}

Enemy::~Enemy()
{
    _cell->SetEntity(nullptr);
    _mediator->notifyDeleteEntity(_cell->GetColumn(), _cell->GetRow());
}
