#pragma once

#include "Src/Entities/ientity.h"

class Cell;
class Field;
class Mediator;

class Character : public IEntity
{
public:
    virtual ~Character() = default;

    virtual void InitMediator(Mediator* mediator) override;

protected:
    Mediator* _mediator;
};
