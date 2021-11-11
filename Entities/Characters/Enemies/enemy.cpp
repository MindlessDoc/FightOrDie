#include "enemy.h"
#include "Cells/cell.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Enemy::Enemy(GraphicField* gameField, GraphicCell* graphicCell, QString filename, int movingTime)
    : _avatar(graphicCell, filename)
    , _gameField(gameField)
    , _graphicCell(graphicCell)
    , _movingTime(movingTime)
{
    _graphicCell->_entity = this;

    _timerForMove = new QTimer();
    connect(_timerForMove, &QTimer::timeout, this, &Enemy::Move);
    _timerForMove->start(_movingTime);
}

Enemy::~Enemy()
{
    _graphicCell->_entity = nullptr;
    delete _timerForMove;
}

void Enemy::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

int Enemy::Type()
{
    return IEntity::ENEMY;
}
