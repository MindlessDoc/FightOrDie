#ifndef GRAPHICFIELD_H
#define GRAPHICFIELD_H
#include<QGraphicsItem>
#include<QPainter>
#include "cell.h"

class GraphicField : public QGraphicsItem
{
public:
    GraphicField(int heightInCells, int widthInCells, Cell*** cells);
private:
    int _heightInCells;
    int _widthInCells;

    Cell*** _cells;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // GRAPHICFIELD_H
