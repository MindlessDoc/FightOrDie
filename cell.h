#ifndef CELL_H
#define CELL_H

#include<QPainter>

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
    Cell(int state);
    ~Cell();

    static int GetHeight();
    static int GetWidth();

    void DrawCell(QPainter *painter, int leftUpX, int leftUpY, int rightDownX, int rightDownY);

private:
    const static int _height = 50;
    const static int _width = 50;

    int _state;
    QPen _pen;
    QBrush _brush;
};

#endif // CELL_H
