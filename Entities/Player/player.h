#pragma once

#include "Entities/ientity.h"

class Player : public IEntity
{
public:
    Player(const Cell* cell);
    virtual void Draw(QPainter* painter) override;
private:
    Avatar _avatar;
};
