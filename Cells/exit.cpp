#include "exit.h"

#include"Entities/Characters/Player/player.h"

Exit::Exit(int coord_x, int coord_y, Mediator* mediator)
    : Cell(coord_x, coord_y, mediator)
{

}

void Exit::Moving(Cell* swapCell)
{
    IEntity* additional = swapCell->GetEntity();
    swapCell->SetEntity(GetEntity());
    SetEntity(additional);

    _mediator->notifySwap(this, swapCell);
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

void Exit::GameOver()
{
    _mediator->notifyGameOver();
}
