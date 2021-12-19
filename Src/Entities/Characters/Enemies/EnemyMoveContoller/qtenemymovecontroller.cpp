#include "qtenemymovecontroller.h"
#include "Src/Entities/Characters/Enemies/enemy.h"
#include <QRandomGenerator>

QtEnemyMoveController::QtEnemyMoveController(Enemy* enemy)
    : EnemyMoveController(enemy)
{
    _timer = new QTimer();
    connect(_timer, &QTimer::timeout, this, &QtEnemyMoveController::CallEnemyMove);
    _timer->start(_enemy->GetMovingTime());
}

void QtEnemyMoveController::CallEnemyMove()
{
    _enemy->Move(QRandomGenerator::global()->bounded(0, int(_enemy->GetDirectionCount())));
}

QtEnemyMoveController::~QtEnemyMoveController()
{
    delete _timer;
}
