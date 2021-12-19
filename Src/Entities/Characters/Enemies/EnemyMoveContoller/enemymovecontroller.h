#pragma once

class Enemy;

class EnemyMoveController
{
public:
    EnemyMoveController(Enemy* enemy);
    virtual ~EnemyMoveController();
protected:
    Enemy* _enemy;
};

