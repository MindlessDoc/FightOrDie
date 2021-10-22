#include "player.h"
#include "Cells/cell.h"
#include "Cells/graphiccell.h"

Player::Player(GraphicCell* cell)
    : _avatar(cell, "C:/QtProjects/OOP/FightOrDie/Src/Player.png")
{
    _cell = cell;
}

void Player::Draw(QPainter* painter)
{
    _avatar.Draw(_cell, painter);
}

void Player::MovingItemCells(int x, int y, Cell*** cells)
{
    static_cast<GraphicCell*>(_cell)->Moving(x, y, cells);
    _cell = static_cast<GraphicCell*>(cells[_cell->GetCoordX() + y][_cell->GetCoordY() + x]);
}
