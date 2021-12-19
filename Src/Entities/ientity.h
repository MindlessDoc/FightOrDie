#pragma once

#include "Src/Loggable/loggable.h"

class IEntity : public Loggable
{
public:
    virtual ~IEntity() = default;
};
