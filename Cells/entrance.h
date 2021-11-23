#pragma once

#include "cell.h"

class Entrance : public Cell
{
public:
    Entrance(int coord_x, int coord_y);
    virtual ~Entrance() = default;

    virtual bool CanMoveIn(const IEntity* entity) override;
};

