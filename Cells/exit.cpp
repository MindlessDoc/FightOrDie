#include "exit.h"

#include"Entities/Characters/Player/player.h"

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
