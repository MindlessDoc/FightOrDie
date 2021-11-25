#pragma once

#include "Loggable/loggable.h"

class IEntity : public Loggable
{
public:
    virtual ~IEntity() = default;
};
