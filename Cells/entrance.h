#pragma once

#include "graphiccell.h"

class Entrance : public GraphicCell
{
public:
    Entrance(int leftUpX, int leftUpY, int rightDownX, int rightDownY);
};

