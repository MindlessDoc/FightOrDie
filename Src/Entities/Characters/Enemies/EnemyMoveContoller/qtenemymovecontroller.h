#pragma once

#include "enemymovecontroller.h"
#include <QTimer>
#include <QTime>
#include "QObject"

class QtEnemyMoveController : public QObject, public EnemyMoveController
{
    Q_OBJECT
public:
    QtEnemyMoveController(Enemy* enemy);
    virtual ~QtEnemyMoveController();

private:
    QTimer* _timer;
public slots:
    void CallEnemyMove();
};
