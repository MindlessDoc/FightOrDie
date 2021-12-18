#pragma once

#include "Entities/ientity.h"

class Cell;
class Field;
class Mediator;

class Character : public IEntity
{
public:
    virtual ~Character() = default;

    void SetMediator(Mediator* mediator);

protected:
    Mediator* _mediator;
};
