#pragma once

#include "graphiccell.h"

class Way : public GraphicCell
{
public:
    Way(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y);
};


