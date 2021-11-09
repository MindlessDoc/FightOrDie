#pragma once

#include<QPainter>
#include "cell.h"
#include <QObject>
#include "Avatar/avatar.h"

class GraphicCell : public QObject, public Cell
{
    Q_OBJECT
public:
    GraphicCell() = default;
    GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y, QString file);
    virtual ~GraphicCell();

    GraphicCell(const GraphicCell& other);
    GraphicCell& operator= (const GraphicCell& other);

    int GetLeftUpX() const;
    int GetLeftUpY() const;
    int GetRightDownX() const;
    int GetRightDownY() const;

    void DrawCell(QPainter *painter);

    virtual void Moving(GraphicCell* swapCell);

protected:
    int _leftUpX, _leftUpY, _rightDownX, _rightDownY;

signals:
    void CellUpdate();

private:
    Avatar _avatar;
};

