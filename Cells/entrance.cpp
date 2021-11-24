#include "entrance.h"

#include"Entities/Characters/Player/player.h"

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

