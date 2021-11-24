#pragma once

#include "Entities/ientity.h"

class Cell;
class Field;
class Mediator;

class Character : public IEntity
{
public:
    virtual ~Character() = default;

    //virtual void Move(int x, int y) = 0;

protected:
    Mediator* _mediator;
};
