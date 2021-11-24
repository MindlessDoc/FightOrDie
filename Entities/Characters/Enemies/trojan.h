#pragma once

#include "enemy.h"

class Trojan : public Enemy
{
public:
    Trojan(Field* gameField, Cell* cell, Mediator* mediator);
    virtual ~Trojan();

//    virtual void Move() override;
//private:
//    void SetNextStep();

//    Cell* _nextStep;
//    QString NextStepAvatarFilename;

//    Vector<Vector<int>> _possibleDirection;
};
