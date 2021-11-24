#pragma once

#include "Entities/Characters/icharacter.h"
#include "Containers/vector.h"
#include <QKeyEvent>
#include "Entities/Items/item.h"

class Player : public ICharacter
{
public:
    Player(int health, int attack, int armor);
    virtual ~Player();

    void Init(Field* gameField, Cell* cell);

    int GetHealth() const;
    int GetAttack() const;
    int GetArmor() const;

    void Move(int x, int y);

    void GameOver();
    void HealthChange(int health);
    void AttackChange(int attack);
    void ArmorChange(int armor);
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
