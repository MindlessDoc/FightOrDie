#pragma once

#include"Entities/ientity.h"

#include"Entities/Characters/Player/player.h"
#include"Entities/Characters/Enemies/virus.h"
#include"Entities/Characters/Enemies/trojan.h"
#include"Entities/Items/HealthItem/healthitem.h"
#include"Entities/Items/ArmorItem/armoritem.h"
#include"Entities/Items/AttackItem/attackitem.h"

#include<memory>
#include<iostream>

class Cell
{
public:

    Cell(int column, int row);
    Cell() = default;
    virtual ~Cell();

    Cell(const Cell& other);
    Cell& operator= (const Cell& other);

    int GetColumn() const;
    int GetRow() const;

    //void Moving(int coord_x, int coord_y);
    //std::shared_ptr<IEntity> _item;

protected:
    int _column, _row;

public:
    IEntity* _entity; // MAKE PRIVATE
    int GetEntityType();
    //IEntity* GetItem();
};
