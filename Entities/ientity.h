#pragma once

#include "Avatar/avatar.h"

class IEntity
{
protected:
    enum Entites
    {
        PLAYER,
        ENEMY,
        HEALTHITEM,
        ATTACKITEM,
        ARMORITEM
    };

public:

    virtual void Draw(QPainter* painter) = 0;
    virtual int Type() = 0;
};
