#include "player.h"
#include "Cells/cell.h"
#include "Cells/graphiccell.h"
#include "Fields/graphicfield.h"

Player::Player(GraphicField* gameField, GraphicCell* graphicCell, int health, int attack, int armor)
    : _avatar(graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Player.png")
    , _gameField(gameField)
    , _graphicCell(graphicCell)
    , _health(health)
    , _attack(attack)
    , _armor(armor)
{
    _graphicCell->_entity = this;
}

Player::~Player()
{
    _graphicCell->_entity = nullptr;
    emit GameOver();
}

void Player::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

void Player::Move(int x, int y)
{
    int newColumn = _graphicCell->GetColumn() + y;
    int newRow = _graphicCell->GetRow() + x;
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells())
    {
        if(_gameField->GetCell(newColumn, newRow)->_entity)
        {
            switch (_gameField->GetCell(newColumn, newRow)->_entity->Type())
            {
            case IEntity::ENEMY:
            {
                delete static_cast<Enemy*>(_gameField->GetCell(newColumn, newRow)->_entity);
                break;
            }
            case IEntity::AIDKIT:
            {
                UseAidKitItem(static_cast<AidKit*>(_gameField->GetCell(newColumn, newRow)->_entity)->GetHealthPointers());
                delete static_cast<AidKit*>(_gameField->GetCell(newColumn, newRow)->_entity);
                break;
            }
            }
        }
        static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow))->Moving(_graphicCell);
        _graphicCell = static_cast<GraphicCell*>(_gameField->GetCell(newColumn, newRow));
    }
}

int Player::Type()
{
    return IEntity::PLAYER;
}

void Player::UseAidKitItem(int plusHealth)
{
    _health += plusHealth;
    emit HealthChange(_health);
}

int Player::GetHealth() const { return _health; }
int Player::GetAttack() const { return _attack; }
int Player::GetArmor() const { return _armor; }
