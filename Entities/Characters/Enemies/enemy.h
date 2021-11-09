#pragma once

#include "Entities/Characters/icharacter.h"
#include <QTimer>
#include <QRandomGenerator>
#include "Containers/vector.h"

class Cell;
class GraphicField;

class Enemy : public QObject, public ICharacter
{
    Q_OBJECT
public:
    Enemy(GraphicField* gameField, GraphicCell* graphicCell, QString filename, int movingTime);
    virtual ~Enemy();
    virtual void Draw(QPainter* painter) override;
    virtual int Type() override;
public slots:
    virtual void Move(); // Think need 'Slot' or no
private:
    Avatar _avatar;

    GraphicField* _gameField;
    GraphicCell* _graphicCell;

    QTimer* _timerForMove;
    int _movingTime;

protected:
    int _directionCount;
    Vector<Vector<int>> _direction;
};
