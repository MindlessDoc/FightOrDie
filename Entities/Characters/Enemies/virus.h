#pragma once

#include "enemy.h"

class Virus : public Enemy
{
public:
    Virus(GraphicField* gameField, GraphicCell* graphicCell);
    virtual ~Virus() = default;

    virtual int Type() override;
    virtual void Move() override;
};

