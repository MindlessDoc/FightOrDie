#pragma once

#include"Entities/Player/player.h"
#include<memory>
#include<iostream>

class Cell
{
public:
    Cell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y);
    Cell() = default;
    virtual ~Cell();

    Cell(const Cell& other);
    Cell& operator= (const Cell& other);

    int GetLeftUpX() const;
    int GetLeftUpY() const;
    int GetRightDownX() const;
    int GetRightDownY() const;

    int GetCoordX() const;
    int GetCoordY() const;

    void Moving(int coord_x, int coord_y);
    //std::shared_ptr<IEntity> _item;

protected:
    int _leftUpX, _leftUpY, _rightDownX, _rightDownY;
    int _coord_x, _coord_y;
public:
    IEntity* _item; // Find out at what point in time shared_ptr will call "delete"
};
