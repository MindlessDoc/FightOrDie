#include "player.h"
#include "Cells/cell.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Player::Player(GraphicField* gameField, GraphicCell* graphicCell)
    : _avatar(graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Player.png")
    , _gameField(gameField)
    , _graphicCell(graphicCell)
{
    _graphicCell->_item = this;
}

void Player::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

void Player::MovingItemCells(int x, int y)
{
    int newColumn = _graphicCell->GetColumn() + y;
    int newRow = _graphicCell->GetRow() + x;
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells())
    {
        _graphicCell->Moving(static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow)));
        _graphicCell = static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow));
    }
}
