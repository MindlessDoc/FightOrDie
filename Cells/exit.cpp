#include "exit.h"

Exit::Exit(int leftUpX, int leftUpY, int rightDownX, int rightDownY)
    : GraphicCell(leftUpX, leftUpY, rightDownX, rightDownY, QPen(), QBrush(Qt::green))
{

}
