#ifndef CELL_H
#define CELL_H

#include<QPainter>
#include"ientity.h"
#include<memory>

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

    static int GetHeight();
    static int GetWidth();

    void DrawCell(QPainter *painter, int leftUpX, int leftUpY, int rightDownX, int rightDownY);

private:
    const static int _height = 70;
    const static int _width = 70;

    int _state;
    QPen _pen;
    QBrush _brush;

    std::shared_ptr<IEntity> _item;
};

#endif // CELL_H
