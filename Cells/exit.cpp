#include "exit.h"

Exit::Exit(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y, QString filename)
    : GraphicCell(leftUpX, leftUpY, rightDownX, rightDownY, coord_x, coord_y, QPen(), QBrush(Qt::green), filename)
{

}
