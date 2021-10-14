#include "way.h"

Way::Way(int leftUpX, int leftUpY, int rightDownX, int rightDownY)
    : GraphicCell(leftUpX, leftUpY, rightDownX, rightDownY, QPen(), QBrush(Qt::gray))
{

}
