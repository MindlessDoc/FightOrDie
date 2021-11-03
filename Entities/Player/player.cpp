#include "player.h"
#include "Cells/cell.h"
#include "Cells/graphiccell.h"

Player::Player(GraphicCell* graphicCell)
    : _avatar(graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Player.png")
{
    _graphicCell = graphicCell;
}

void Player::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

void Player::MovingItemCells(int x, int y, Vector<Vector<Cell*>> cells)
{
    int newColumn = _graphicCell->GetColumn() + y;
    int newRow = _graphicCell->GetRow() + x;
    if(newColumn >= 0 && newRow >= 0 && newColumn < 5 && newRow < 8)
    {
        _graphicCell->Moving(x, y, cells);
        _graphicCell = static_cast<GraphicCell*>(cells[newColumn][newRow]);
    }
}
