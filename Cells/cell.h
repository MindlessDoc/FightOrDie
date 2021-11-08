#pragma once

#include"Entities/Characters/Player/player.h"
#include"Entities/Characters/Enemies/enemy.h"
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
    IEntity* _item; // Find out at what point in time shared_ptr will call "delete"
};
