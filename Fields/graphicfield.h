#ifndef GRAPHICFIELD_H
#define GRAPHICFIELD_H

#include "field.h"
#include <QGraphicsItem>

class GraphicField : public QGraphicsItem, public Field
{
public:
    GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    virtual ~GraphicField();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // GRAPHICFIELD_H
