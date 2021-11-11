#pragma once

#include "enemy.h"

class Virus : public Enemy
{
public:
    Virus(GraphicField* gameField, GraphicCell* graphicCell);
    virtual void Move() override;
};

