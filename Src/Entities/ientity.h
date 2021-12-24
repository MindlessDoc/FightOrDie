#pragma once

#include "Src/Serializable/serializable.h"

#include "Src/Loggable/loggable.h"

class IEntity : public Loggable, public Serializable
{
public:
    virtual ~IEntity() = default;
};
