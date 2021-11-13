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
            case IEntity::VIRUS:
            case IEntity::TROJAN:
            {
                delete _gameField->GetCell(newColumn, newRow)->_entity;
                break;
            }
            case IEntity::IMMORTAL:
            {
                delete this;
                break;
            }
            case IEntity::HEALTHITEM:
            {
                UseHealthItem(static_cast<HealthItem*>(_gameField->GetCell(newColumn, newRow)->_entity)->GetHealthPointers());
                delete _gameField->GetCell(newColumn, newRow)->_entity;
                break;
            }
            case IEntity::ATTACKITEM:
            {
                UseAttackItem(static_cast<AttackItem*>(_gameField->GetCell(newColumn, newRow)->_entity)->GetAttackPointers());
                delete _gameField->GetCell(newColumn, newRow)->_entity;
                break;
            }
            case IEntity::ARMORITEM:
            {
                UseArmorItem(static_cast<ArmorItem*>(_gameField->GetCell(newColumn, newRow)->_entity)->GetArmorPointers());
                delete _gameField->GetCell(newColumn, newRow)->_entity;
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

void Player::UseHealthItem(int plusHealth)
{
    _health += plusHealth;
    emit HealthChange(_health);
}

void Player::UseAttackItem(int plusAttck)
{
    _attack += plusAttck;
    emit AttackChange(_attack);
}

void Player::UseArmorItem(int plusArmor)
{
    _armor += plusArmor;
    emit ArmorChange(_armor);
}


int Player::GetHealth() const { return _health; }
int Player::GetAttack() const { return _attack; }
int Player::GetArmor() const { return _armor; }
