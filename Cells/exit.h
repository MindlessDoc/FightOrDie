#pragma once

#include "cell.h"

class Exit : public Cell
{
public:
    Exit(int coord_x, int coord_y);
    virtual ~Exit() = default;

    virtual void Moving(Cell* swapCell) override;
    virtual bool CanMoveIn(const IEntity* entity) override;

    void GameOver();
};
