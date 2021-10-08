#ifndef GRAPHICFIELD_H
#define GRAPHICFIELD_H
#include<QGraphicsItem>
#include<QPainter>
#include "cell.h"

class GraphicField : public QGraphicsItem
{
public:
    GraphicField(int heightInCells, int widthInCells, std::shared_ptr<std::shared_ptr<Cell[]>[]> cells);
private:
    int _heightInCells;
    int _widthInCells;

    std::shared_ptr<std::shared_ptr<Cell[]>[]> _cells;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // GRAPHICFIELD_H
