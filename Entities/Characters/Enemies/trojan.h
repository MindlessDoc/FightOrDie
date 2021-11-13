#pragma once

#include "enemy.h"

class Trojan : public Enemy
{
public:
    Trojan(GraphicField* gameField, GraphicCell* graphicCell);
    virtual ~Trojan();

    virtual int Type() override;
    virtual void Move() override;
private:
    void SetNextStep();

    GraphicCell* _nextStep;
    QString NextStepAvatarFilename;

    Vector<Vector<int>> _possibleDirection;
};
