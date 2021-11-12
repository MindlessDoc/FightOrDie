#pragma once

#include "enemy.h"

class Immortal : public Enemy
{
public:
    Immortal(GraphicField* gameField, GraphicCell* graphicCell);
    virtual void Move() override;
    virtual int Type() override;
private:
    int _actualVertiaclDirection;

    void UpdateActualDirection();

};

