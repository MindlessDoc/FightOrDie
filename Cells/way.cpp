#include "way.h"

Way::Way(int coord_x, int coord_y)
    : Cell(coord_x, coord_y)
{

}

bool Way::CanMoveIn(const IEntity* entity)
{
    return true;
}
