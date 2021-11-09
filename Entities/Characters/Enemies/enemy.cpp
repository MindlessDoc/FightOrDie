#include "enemy.h"
#include "Cells/cell.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Enemy::Enemy(GraphicField* gameField, GraphicCell* graphicCell, QString filename, int movingTime)
    : _avatar(graphicCell, filename)
    , _gameField(gameField)
    , _graphicCell(graphicCell)
    , _movingTime(movingTime)
{
    _graphicCell->_entity = this;

    _timerForMove = new QTimer();
    connect(_timerForMove, &QTimer::timeout, this, &Enemy::Move);
    _timerForMove->start(_movingTime);

}

Enemy::~Enemy()
{
    _graphicCell->_entity = nullptr;
    delete _timerForMove;
}

void Enemy::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

void Enemy::Move()
{
    int index = QRandomGenerator::global()->bounded(0, _directionCount);
    int newColumn = _graphicCell->GetColumn() + _direction[index][0];
    int newRow = _graphicCell->GetRow() + _direction[index][1];
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells())
    {
        if(((_gameField->GetCell(newColumn, newRow)->_entity && _gameField->GetCell(newColumn, newRow)->_entity->Type() == IEntity::PLAYER)
                || (!_gameField->GetCell(newColumn, newRow)->_entity))
                && static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->CanMoveIn())
        {
            if(_gameField->GetCell(newColumn, newRow)->_entity && _gameField->GetCell(newColumn, newRow)->_entity->Type() == IEntity::PLAYER)
            {
                delete static_cast<Player*>(_gameField->GetCell(newColumn, newRow)->_entity);
            }
            static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->Moving(_graphicCell);
            _graphicCell = static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow));

        }        
    }
}

int Enemy::Type()
{
    return IEntity::ENEMY;
}
