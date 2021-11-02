#pragma once

#include "graphiccell.h"

class Exit : public GraphicCell
{
public:
    Exit(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y,
         QString filename = "C:/QtProjects/OOP/FightOrDie/Src/Portal.png");
};
