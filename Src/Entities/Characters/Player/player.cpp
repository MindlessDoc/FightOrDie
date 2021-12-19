#include "player.h"
#include "Src/Cells/cell.h"
#include "Src/Fields/field.h"

#include "Src/Entities/Characters/Enemies/virus.h"
#include "Src/Entities/Characters/Enemies/immortal.h"
#include "Src/Entities/Characters/Enemies/trojan.h"

#include "Src/Entities/Items/ArmorItem/armoritem.h"
#include "Src/Entities/Items/AttackItem/attackitem.h"
#include "Src/Entities/Items/HealthItem/healthitem.h"

#include "Src/Application/mediator.h"

Player::Player(int health, int attack, int armor)
    : _health(health)
    , _attack(attack)
    , _armor(armor)
{
    _gameField = nullptr;
    _cell = nullptr;
}

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
    if(_gameField->CheckOnInclusion(newColumn, newRow))
    {
        IEntity* additional = _gameField->GetCell(newColumn, newRow)->GetEntity();
        if(additional)
        {
            if(typeid (*additional) == typeid (Virus)
                    || typeid (*additional) == typeid (Trojan))
            {
                delete additional;
            }
            else if(typeid (*additional) == typeid (Immortal))
            {
                delete this;
                return; // FIX
            }
            else if(typeid (*additional) == typeid (HealthItem))
            {
                UseHealthItem(static_cast<HealthItem*>(_gameField->GetCell(newColumn, newRow)->GetEntity())->GetHealthPointers());
                delete additional;
            }
            else if(typeid (*additional) == typeid (AttackItem))
            {
                UseAttackItem(static_cast<AttackItem*>(_gameField->GetCell(newColumn, newRow)->GetEntity())->GetAttackPointers());
                delete additional;
            }
            else if(typeid (*additional) == typeid (ArmorItem))
            {
                UseArmorItem(static_cast<ArmorItem*>(_gameField->GetCell(newColumn, newRow)->GetEntity())->GetArmorPointers());
                delete additional;
            }
        }
        _gameField->GetCell(newColumn, newRow)->Moving(_cell);
        _cell = _gameField->GetCell(newColumn, newRow);
        notify();
    }
}

void Player::UseHealthItem(int plusHealth)
{
    _health += plusHealth;
    notify();
    _mediator->notifyPlayerHealthChange(_health);
}

void Player::UseAttackItem(int plusAttck)
{
    _attack += plusAttck;
    notify();
    _mediator->notifyPlayerAttackChange(_attack);
}

void Player::UseArmorItem(int plusArmor)
{
    _armor += plusArmor;
    notify();
    _mediator->notifyPlayerArmorChange(_armor);
}

void Player::GameOver()
{
    _mediator->notifyGameOver();
}

int Player::GetHealth() const { return _health; }
int Player::GetAttack() const { return _attack; }
int Player::GetArmor() const { return _armor; }

std::string Player::LogOut() const
{
    return "Player Info:\nHealth: " + std::to_string(_health) +
            " Attack: " + std::to_string(_attack) +
            " Armor: " + std::to_string(_armor) + "\n" +
            "Coordinates: column = " + std::to_string(_cell->GetColumn())+
            " row = " + std::to_string(_cell->GetRow()) + "\n";
}
