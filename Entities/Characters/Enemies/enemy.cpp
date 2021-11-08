#include "enemy.h"
#include "Cells/cell.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Enemy::Enemy(GraphicField* gameField, GraphicCell* graphicCell)
    : _avatar(graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Player.png")
    , _gameField(gameField)
    , _graphicCell(graphicCell)
{
    _graphicCell->_item = this;
}

void Enemy::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

/*void Enemy::Move()
{
    int newColumn = _graphicCell->GetColumn() + y;
    int newRow = _graphicCell->GetRow() + x;
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells())
    {
        static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->Moving(_graphicCell);
        _graphicCell = static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow));
    }
}*/
