#pragma once

#include "field.h"
#include <QGraphicsItem>

class MainWindow;

class GraphicField : public QObject, public Field, public QGraphicsItem
{
    Q_OBJECT
public:
    GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    virtual ~GraphicField();

    void InitGraphicField(Player* player);

    GraphicField(const GraphicField& other);
    GraphicField& operator= (const GraphicField& other);

    GraphicField(GraphicField&& other);
    GraphicField& operator= (GraphicField&& other);

    //const Player* GetPlayer();

public slots:
    void MovingPlayerSlot(int x, int y);
    void GameOver();
signals:
    void MovingPlayerSignal(int x, int y);
    void DoCloseWindow();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    GraphicCell* _entrance;
    GraphicCell* _exit;
    //Player* _player;
};

