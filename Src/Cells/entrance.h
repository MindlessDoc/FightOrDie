#pragma once

#include "cell.h"
#include "Src/Application/mediator.h"

class Entrance : public Cell
{
public:
    Entrance(int coord_x, int coord_y);
    Entrance(int coord_x, int coord_y, Mediator* mediator);
    virtual ~Entrance() = default;

    virtual bool CanMoveIn(const IEntity* entity) override;
};

