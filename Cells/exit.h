#pragma once

#include "graphiccell.h"

class Exit : public GraphicCell
{
    Q_OBJECT
public:
    Exit(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y,
         QString filename = "C:/QtProjects/OOP/FightOrDie/Src/Portal.png");
    virtual void Moving(GraphicCell* swapCell) override;
    virtual int Type() override;
    virtual bool CanMoveIn() override;
signals:
    void GameOver();
};
