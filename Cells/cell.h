#ifndef CELL_H
#define CELL_H

#include<QPainter>
#include"ientity.h"
#include<memory>
#include<iostream>

enum CellState
{
    ENTRANCE,
    EXIT,
    BARRIER,
    WAY
};

class Cell
{
public:
    Cell();
    Cell(int state);
    ~Cell();

    void DrawCell(QPainter *painter, int leftUpX, int leftUpY,
                  int rightDownX, int rightDownY);

private:
    int _state;
    QPen _pen;
    QBrush _brush;

    std::shared_ptr<IEntity> _item;
};

#endif // CELL_H
