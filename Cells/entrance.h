#ifndef ENTRANCE_H
#define ENTRANCE_H
#include "graphiccell.h"

class Entrance : public GraphicCell
{
public:
    Entrance(int leftUpX, int leftUpY, int rightDownX, int rightDownY);
};

#endif // ENTRANCE_H
