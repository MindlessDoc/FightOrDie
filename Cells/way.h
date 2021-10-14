#ifndef WAY_H
#define WAY_H
#include "graphiccell.h"

class Way : public GraphicCell
{
public:
    Way(int leftUpX, int leftUpY, int rightDownX, int rightDownY);
};

#endif // WAY_H
