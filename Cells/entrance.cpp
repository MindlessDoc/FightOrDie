#include "entrance.h"

Entrance::Entrance(int leftUpX, int leftUpY, int rightDownX, int rightDownY)
    : GraphicCell(leftUpX, leftUpY, rightDownX, rightDownY, QPen(), QBrush(Qt::yellow))
{

}
