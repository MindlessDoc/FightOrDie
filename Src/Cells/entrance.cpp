#include "entrance.h"

#include"Src/Entities/Characters/Player/player.h"

Entrance::Entrance(int coord_x, int coord_y)
    : Cell(coord_x, coord_y)
{

}

Entrance::Entrance(int coord_x, int coord_y, Mediator* mediator)
    : Cell(coord_x, coord_y, mediator)
{

}

bool Entrance::CanMoveIn(const IEntity* entity)
{
    if(typeid (entity) == typeid (Player))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Entrance::Serialize(std::ostream &os)
{
    os << typeid (Entrance).name() << " " << GetColumn() << " " << GetRow() << std::endl;
    if(GetEntity())
        GetEntity()->Serialize(os);
}

