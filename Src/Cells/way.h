#pragma once

#include "cell.h"
#include "Src/Application/mediator.h"

class Way : public Cell
{
public:
    Way(int coord_x, int coord_y);
    Way(int coord_x, int coord_y, Mediator* mediator);
    virtual ~Way() = default;

    virtual bool CanMoveIn(const IEntity* entity) override;
};


