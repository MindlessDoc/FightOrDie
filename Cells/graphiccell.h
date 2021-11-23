#pragma once

#include<QPainter>
#include "cell.h"
#include <QObject>
#include "Avatar/avatar.h"

class GraphicIEntity; // REPLACE WITH FILE INCLUDE

class GraphicCell : public QObject
{
    Q_OBJECT
public:
    GraphicCell(int leftUpX, int leftUpY, int rightDownX, int rightDownY,
                Cell* cell,  QString file);
    virtual ~GraphicCell() = default;

    GraphicCell(const GraphicCell& other);
    GraphicCell& operator= (const GraphicCell& other);

    int GetLeftUpX() const;
    int GetLeftUpY() const;
    int GetRightDownX() const;
    int GetRightDownY() const;

    void DrawCell(QPainter *painter);
    void UpdateAvatar(QString filename);

private:
    Cell* _cell;

    GraphicIEntity* _graphicEntity;

    int _leftUpX, _leftUpY, _rightDownX, _rightDownY;



    //Maybe add scale//

    Avatar _avatar;

signals:
    void CellUpdate();
};

