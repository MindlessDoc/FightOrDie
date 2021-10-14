#ifndef EXIT_H
#define EXIT_H
#include "graphiccell.h"

class Exit : public GraphicCell
{
public:
    Exit(int leftUpX, int leftUpY, int rightDownX, int rightDownY);
};

#endif // EXIT_H
