#pragma once

#include "Avatar/avatar.h"

class IEntity
{
protected:
    enum Entites
    {
        PLAYER,
        ENEMY
    };

public:
    virtual void Draw(QPainter* painter) = 0;
    virtual int Type() = 0;
};
