#include "way.h"

Way::Way(int coord_x, int coord_y)
    : Cell(coord_x, coord_y)
{

}

Way::Way(int coord_x, int coord_y, Mediator* mediator)
    : Cell(coord_x, coord_y, mediator)
{

}

bool Way::CanMoveIn(const IEntity* entity)
{
    return true;
}

void Way::Serialize(std::ostream &os)
{
    os << typeid (Way).name() << " " << GetColumn() << " " << GetRow() << std::endl;
    if(GetEntity())
        GetEntity()->Serialize(os);
}
