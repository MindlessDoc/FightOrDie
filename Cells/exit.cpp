#include "exit.h"

#include"Entities/Characters/Player/player.h"
#include"Entities/Characters/Enemies/virus.h"
#include"Entities/Characters/Enemies/trojan.h"
#include"Entities/Characters/Enemies/immortal.h"
#include"Entities/Items/HealthItem/healthitem.h"
#include"Entities/Items/ArmorItem/armoritem.h"
#include"Entities/Items/AttackItem/attackitem.h"


Exit::Exit(int coord_x, int coord_y)
    : Cell(coord_x, coord_y)
{

}

void Exit::Moving(Cell* swapCell)
{
    IEntity* additional = swapCell->GetEntity();
    swapCell->SetEntity(GetEntity());
    SetEntity(additional);
    GameOver();
}

bool Exit::CanMoveIn(const IEntity* entity)
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
