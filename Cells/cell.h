#ifndef CELL_H
#define CELL_H

#include<QPainter>
#include"Entities/ientity.h"
#include<memory>
#include<iostream>

class Cell
{
public:
    Cell(int leftUpX, int leftUpY, int rightDownX, int rightDownY);
    Cell() = default;
    virtual ~Cell();

    Cell(const Cell& other);
    Cell& operator= (const Cell& other);

    int GetLeftUpX() const;
    int GetLeftUpY() const;
    int GetRightDownX() const;
    int GetRightDownY() const;

protected:
    int _leftUpX, _leftUpY, _rightDownX, _rightDownY;

private:
    std::shared_ptr<IEntity> _item; // Find out at what point in time shared_ptr will call "delete"
};

#endif // CELL_H
