#pragma once

#include "graphiccell.h"

class Entrance : public GraphicCell
{
public:
    Entrance(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y,
             QString filename = "C:/QtProjects/OOP/FightOrDie/Src/Door.png");
};

