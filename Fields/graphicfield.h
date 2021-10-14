#ifndef GRAPHICFIELD_H
#define GRAPHICFIELD_H

#include"Application/mainwindow.h"
#include "field.h"

class GraphicField : public QGraphicsItem, public Field
{
public:
    GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    ~GraphicField();
private:
    std::shared_ptr<MainWindow> _mainWindow;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // GRAPHICFIELD_H
