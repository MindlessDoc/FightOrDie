#pragma once

#include "Entities/Characters/icharacter.h"
#include "Containers/vector.h"
#include <QKeyEvent>
#include <QObject>

class Cell;
class GraphicField;

class Player : public QObject, public ICharacter
{
    Q_OBJECT
public:
    Player(GraphicField* gameField, GraphicCell* graphicCell);
    ~Player();
    virtual void Draw(QPainter* painter) override;
    virtual int Type() override;
public slots:
    void Move(int x, int y);
signals:
    void GameOver();
private:
    Avatar _avatar;
    GraphicField* _gameField;
    GraphicCell* _graphicCell;
};
