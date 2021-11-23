#pragma once

#include "field.h"
#include "Cells/graphiccell.h"
#include <QGraphicsItem>
#include "Cells/CellFactory/cellfactory.h"

class MainWindow;

class GraphicField : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    GraphicField(Field* field, int heightOfCell, int widthOfCell);
    virtual ~GraphicField();

    GraphicField(const GraphicField& other);
    GraphicField& operator= (const GraphicField& other);

    GraphicField(GraphicField&& other);
    GraphicField& operator= (GraphicField&& other);

    int GetHeightOfCell();
    int GetWidthOfCell();

public slots:
    void GameOver();
signals:
    void DoCloseWindow();

private:
    Field* _field;

    int _heightOfCell;
    int _widthOfCell;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    Vector<Vector<GraphicCell*>> _graphicCells;

    CellFactory _factory;

//    GraphicCell* _entrance;
//    GraphicCell* _exit;
};

