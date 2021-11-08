#include "enemy.h"
#include "Cells/cell.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Enemy::Enemy(GraphicField* gameField, GraphicCell* graphicCell)
    : _avatar(graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Enemy.png")
    , _gameField(gameField)
    , _graphicCell(graphicCell)
    , _movingTime(1000)
{
    _graphicCell->_item = this;

    _timerForMove = new QTimer();
    connect(_timerForMove, &QTimer::timeout, this, &Enemy::Move);
    _timerForMove->start(_movingTime);

    //Think how to reduce
    _direction.resize(4);
    for(int i = 0; i < 4; i++)
    {
        _direction[i].resize(2);
    }

    _direction[0][0] = -1; _direction[0][1] = 0;
    _direction[1][0] = 1; _direction[1][1] = 0;
    _direction[2][0] = 0; _direction[2][1] = -1;
    _direction[3][0] = 0; _direction[3][1] = 1;
}

Enemy::~Enemy()
{
    delete _timerForMove;
}

void Enemy::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

void Enemy::Move()
{
    int index = QRandomGenerator::global()->bounded(0, 4);
    int newColumn = _graphicCell->GetColumn() + _direction[index][0];
    int newRow = _graphicCell->GetRow() + _direction[index][1];
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells())
    {
        static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->Moving(_graphicCell);
        _graphicCell = static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow));
    }
}
