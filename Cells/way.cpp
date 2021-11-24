#include "way.h"

Way::Way(int coord_x, int coord_y, Mediator* mediator)
    : Cell(coord_x, coord_y, mediator)
{

}

bool Way::CanMoveIn(const IEntity* entity)
{
    return true;
}
