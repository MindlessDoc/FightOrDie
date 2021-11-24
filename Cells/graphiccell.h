#pragma once

#include<QPainter>
#include "cell.h"
#include <QObject>
#include "Avatar/avatar.h"
#include "Entities/EntityFactory/entityfactory.h"

class GraphicEntity;
//class EntityFactory;

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

    GraphicEntity* GetGraphicEntity();
    Cell* GetCell();

    void DrawCell(QPainter *painter);
    void UpdateAvatar(QString filename);

    virtual void EntitySwap(GraphicCell* graphicCell);
    virtual void DeleteGraphicEntity();

private:
    Cell* _cell;

    GraphicEntity* _graphicEntity;

    int _leftUpX, _leftUpY, _rightDownX, _rightDownY;

    EntityFactory _entityFactory;

    //Maybe add scale//

    Avatar _avatar;

signals:
    void CellUpdate();
};

