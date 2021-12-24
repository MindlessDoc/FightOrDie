#pragma once

#include "Src/Serializable/serializable.h"

#include "Src/Loggable/loggable.h"

class Mediator;

class IEntity : public Loggable, public Serializable
{
public:
    virtual ~IEntity() = default;
    virtual void InitMediator(Mediator* mediator) = 0;
};
