#pragma once

#include "Src/Entities/Characters/icharacter.h"
#include "Src/Containers/vector.h"
#include <QKeyEvent>
#include "Src/Entities/Items/item.h"

class Player : public Character
{
public:
    Player(int health, int attack, int armor);
    Player(int health, int attack, int armor, Mediator* mediator);
    virtual ~Player();

    void Die();

    void Init(Field* gameField, Cell* cell);

    int GetHealth() const;
    int GetAttack() const;
    int GetArmor() const;

    virtual void Move(int x, int y);

    void GameOver();
    void HealthChange(int health);
    void AttackChange(int attack);
    void ArmorChange(int armor);

    virtual std::string LogOut() const override;

    virtual void Serialize(std::ostream& os) override;

private:
    Field* _gameField;
    Cell* _cell;

    int _health;
    int _attack;
    int _armor;

    void UseHealthItem(int plusHealth);
    void UseAttackItem(int plusAttck);
    void UseArmorItem(int plusArmor);

    //void UseItem(Item* item);
};
