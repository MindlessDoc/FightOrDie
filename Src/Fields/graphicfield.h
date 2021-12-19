#pragma once

#include "field.h"
#include "Src/Cells/graphiccell.h"
#include <QGraphicsItem>
#include "Src/Cells/CellFactory/cellfactory.h"

class MainWindow;

class GraphicField : public QGraphicsItem
{
public:
    GraphicField(Field* field, int heightOfCell, int widthOfCell);
    virtual ~GraphicField();

    GraphicField(const GraphicField& other);
    GraphicField& operator= (const GraphicField& other);

    GraphicField(GraphicField&& other);
    GraphicField& operator= (GraphicField&& other);

    int GetHeightOfCell();
    int GetWidthOfCell();

    GraphicCell* GetGraphicCell(int column, int row);

private:
    Field* _field;

    int _heightOfCell;
    int _widthOfCell;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    Vector<Vector<GraphicCell*>> _graphicCells;

    CellFactory _cellFactory;

//    GraphicCell* _entrance;
//    GraphicCell* _exit;
};

