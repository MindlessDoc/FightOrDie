#pragma once

#include "ientity.h"
#include <QPainter>
#include "Avatar/avatar.h"

class GraphicEntity
{
public:
    GraphicEntity();
    virtual void Draw(QPainter* painter);
private:
    Avatar _avatar;
};
