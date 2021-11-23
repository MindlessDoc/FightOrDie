#pragma once

#include "cell.h"

class Way : public Cell
{
public:
    Way(int coord_x, int coord_y);
    virtual ~Way() = default;

    virtual bool CanMoveIn(const IEntity* entity) override;
};


