#include "qtenemymovecontroller.h"
#include "Entities/Characters/Enemies/enemy.h"
#include <QRandomGenerator>

QtEnemyMoveController::QtEnemyMoveController(Enemy* enemy)
    : EnemyMoveController(enemy)
{
    _timer = new QTimer();
    _timer->start(_enemy->GetMovingTime());
    connect(_timer, &QTimer::timeout, this, &QtEnemyMoveController::CallEnemyMove);
}

void QtEnemyMoveController::CallEnemyMove()
{
    _enemy->Move(QRandomGenerator::global()->bounded(0, int(_enemy->GetDirectionCount())));
}

QtEnemyMoveController::~QtEnemyMoveController()
{
    delete _timer;
}
