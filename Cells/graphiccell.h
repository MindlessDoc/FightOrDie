#ifndef GRAPHICCELL_H
#define GRAPHICCELL_H

#include<QPainter>

class GraphicCell
{
public:
    GraphicCell();

    void DrawCell(QPainter *painter, int leftUpX, int leftUpY, int rightDownX, int rightDownY);

private:
    QPen _pen;
    QBrush _brush;
};

#endif // GRAPHICCELL_H
