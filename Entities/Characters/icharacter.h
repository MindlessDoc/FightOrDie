#pragma once

#include "Entities/ientity.h"

class Cell;
class Field;
class Mediator;

class ICharacter : public IEntity
{
public:
    virtual ~ICharacter() = default;
protected:
    Mediator* _mediator;
};
