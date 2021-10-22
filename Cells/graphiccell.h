#pragma once

#include<QPainter>
#include "cell.h"
#include <QObject>

class GraphicCell : public QObject, public Cell
{
    Q_OBJECT
public:
    GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y, QPen pen, QBrush brush);
    GraphicCell() = default;
    virtual ~GraphicCell();

    GraphicCell(const GraphicCell& other);
    GraphicCell& operator= (const GraphicCell& other);

    int GetLeftUpX() const;
    int GetLeftUpY() const;
    int GetRightDownX() const;
    int GetRightDownY() const;

    void DrawCell(QPainter *painter);

    void Moving(int x, int y, Cell*** cells);

protected:
    int _leftUpX, _leftUpY, _rightDownX, _rightDownY;

signals:
    void CellUpdate();

private:
    QPen _pen;
    QBrush _brush;
};

