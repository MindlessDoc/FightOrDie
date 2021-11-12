#include "way.h"

Way::Way(int leftUpX, int leftUpY, int rightDownX, int rightDownY, int coord_x, int coord_y, QString filename)
    : GraphicCell(leftUpX, leftUpY, rightDownX, rightDownY, coord_x, coord_y, filename)
{

}

int Way::Type()
{
    return GraphicCellsTypes::WAY;
}

bool Way::CanMoveIn()
{
    if(GetEntityType() == IEntity::NULLPTR || GetEntityType() == IEntity::PLAYER)
        return true;
    else
        return false;
}
