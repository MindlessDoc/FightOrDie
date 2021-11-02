#pragma once

#include "field.h"
#include <QGraphicsItem>

class GraphicField : public QObject, public Field, public QGraphicsItem
{
    Q_OBJECT
public:
    GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    virtual ~GraphicField();

    GraphicField(const GraphicField& other);
    GraphicField& operator= (const GraphicField& other);

    GraphicField(GraphicField&& other);
    GraphicField& operator= (GraphicField&& other);
public slots:
    void MovingPlayer(int x, int y);
signals:
    void MovingItemCells(int x, int y, Vector<Vector<std::shared_ptr<Cell>>> cells);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    Player* _player;
};

