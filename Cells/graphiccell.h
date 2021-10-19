#pragma once

#include<QPainter>
#include "cell.h"

class GraphicCell : public Cell, public QWidget
{
public:
    GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y, QPen pen, QBrush brush);
    GraphicCell() = default;
    virtual ~GraphicCell();

    GraphicCell(const GraphicCell& other);
    GraphicCell& operator= (const GraphicCell& other);

    void DrawCell(QPainter *painter);

signals:
    void Moving(int coord_x, int coord_y);

private:
    QPen _pen;
    QBrush _brush;
};

