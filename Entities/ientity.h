#pragma once

#include "Avatar/avatar.h"

class Cell;

class IEntity
{
public:
    enum Entites
    {
        NULLPTR,
        PLAYER,
        ENEMY,
        IMMORTAL,
        HEALTHITEM,
        ATTACKITEM,
        ARMORITEM
    };

public:
    virtual void Draw(QPainter* painter) = 0;
    virtual int Type() = 0;
};
