#pragma once

#include "graphiccell.h"

class Exit : public GraphicCell
{
public:
    Exit(int leftUpX, int leftUpY, int rightDownX, int rightDownY);
};
