#include "entrance.h"

Entrance::Entrance(int coord_x, int coord_y)
    : Cell(coord_x, coord_y)
{

}

bool Entrance::CanMoveIn(const IEntity* entity)
{
    return false;
}

