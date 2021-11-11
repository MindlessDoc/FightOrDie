#pragma once

#include "enemy.h"

class Trojan : public Enemy
{
public:
    Trojan(GraphicField* gameField, GraphicCell* graphicCell);
    virtual void Move() override;
};
