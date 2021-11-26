#pragma once

#include "cell.h"
#include "Application/mediator.h"

class Exit : public Cell
{
public:
    Exit(int coord_x, int coord_y, Mediator* mediator);
    virtual ~Exit() = default;

    virtual void Moving(Cell* swapCell) override;
    virtual bool CanMoveIn(const IEntity* entity) override;

    void GameOver();
};
