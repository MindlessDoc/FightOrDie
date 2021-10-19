#pragma once

#include "field.h"
#include <QGraphicsItem>

class GraphicField : public QGraphicsItem, public Field
{
public:
    GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    virtual ~GraphicField();

    GraphicField(const GraphicField& other);
    GraphicField& operator= (const GraphicField& other);

    GraphicField(GraphicField&& other);
    GraphicField& operator= (GraphicField&& other);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

