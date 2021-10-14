#ifndef GRAPHICCELL_H
#define GRAPHICCELL_H

#include<QPainter>
#include "cell.h"

class GraphicCell : public Cell
{
public:
    GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, QPen pen, QBrush brush);
    GraphicCell() = default;

    void DrawCell(QPainter *painter);

private:
    QPen _pen;
    QBrush _brush;
};

#endif // GRAPHICCELL_H
