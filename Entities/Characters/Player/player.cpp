#include "player.h"
#include "Cells/cell.h"
#include "Fields/field.h"

#include "Entities/Characters/Enemies/virus.h"
#include "Entities/Characters/Enemies/immortal.h"
#include "Entities/Characters/Enemies/trojan.h"

#include "Entities/Items/ArmorItem/armoritem.h"
#include "Entities/Items/AttackItem/attackitem.h"
#include "Entities/Items/HealthItem/healthitem.h"

Player::Player(int health, int attack, int armor, Mediator* mediator)
    : _health(health)
    , _attack(attack)
    , _armor(armor)
{
    _gameField = nullptr;
    _cell = nullptr;

    _mediator = mediator;
}

void Player::Init(Field* gameField, Cell* cell)
{
    _gameField = gameField;
    _cell = cell;

    _cell->SetEntity(this);
}

Player::~Player()
{
    _cell->SetEntity(nullptr);
    GameOver();
}

void Player::Move(int x, int y)
{
    int newColumn = _cell->GetColumn() + y;
    int newRow = _cell->GetRow() + x;
    if(newColumn >= 0 && newRow >= 0 && newColumn < _gameField->GetHeightInCells() && newRow < _gameField->GetWidthInCells())
    {
        IEntity* additional = _gameField->GetCell(newColumn, newRow)->GetEntity();
        if(additional)
        {
            if(typeid (additional) == typeid (Virus)
                    || typeid (additional) == typeid (Trojan))
            {
                delete additional;
            }
            else if(typeid (additional) == typeid (Immortal))
            {
                delete this;
            }
            else if(typeid (additional) == typeid (HealthItem))
            {
                UseHealthItem(static_cast<HealthItem*>(_gameField->GetCell(newColumn, newRow)->GetEntity())->GetHealthPointers());
                delete additional;
            }
            else if(typeid (additional) == typeid (AttackItem))
            {
                UseAttackItem(static_cast<AttackItem*>(_gameField->GetCell(newColumn, newRow)->GetEntity())->GetAttackPointers());
                delete additional;
            }
            else if(typeid (additional) == typeid (ArmorItem))
            {
                UseArmorItem(static_cast<ArmorItem*>(_gameField->GetCell(newColumn, newRow)->GetEntity())->GetArmorPointers());
                delete additional;
            }
        }
        _gameField->GetCell(newColumn, newRow)->Moving(_cell);
        _cell = _gameField->GetCell(newColumn, newRow);
    }
}

void Player::UseHealthItem(int plusHealth)
{
    _health += plusHealth;
    _mediator->notifyPlayerHealthChange(_health);
}

void Player::UseAttackItem(int plusAttck)
{
    _attack += plusAttck;
    _mediator->notifyPlayerAttackChange(_attack);
}

void Player::UseArmorItem(int plusArmor)
{
    _armor += plusArmor;
    _mediator->notifyPlayerArmorChange(_armor);
}

void Player::GameOver()
{
    _mediator->notifyGameOver();
}

int Player::GetHealth() const { return _health; }
int Player::GetAttack() const { return _attack; }
int Player::GetArmor() const { return _armor; }
