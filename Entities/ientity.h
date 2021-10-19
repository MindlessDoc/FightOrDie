#pragma once

#include "Avatar/avatar.h"

class IEntity
{
public:
    virtual void Draw(QPainter* painter) = 0;
};
