#pragma once

#include "Entities/Characters/icharacter.h"
#include "Containers/vector.h"
#include <QKeyEvent>
#include <QObject>
#include "Entities/Items/item.h"

class Cell;
class GraphicField;

class Player : public QObject, public ICharacter
{
    Q_OBJECT
public:
    Player(GraphicField* gameField, GraphicCell* graphicCell, int health, int attack, int armor);
    virtual ~Player();
    virtual void Draw(QPainter* painter) override;
    virtual int Type() override;

    int GetHealth() const;
    int GetAttack() const;
    int GetArmor() const;

public slots:
    void Move(int x, int y);

signals:
    void GameOver();
    void HealthChange(int health);
    void AttackChange(int attack);
    void ArmorChange(int armor);
private:
    Avatar _avatar;
    GraphicField* _gameField;
    GraphicCell* _graphicCell;

    int _health;
    int _attack;
    int _armor;

    void UseHealthItem(int plusHealth);
    void UseAttackItem(int plusAttck);
    void UseArmorItem(int plusArmor);

    //void UseItem(Item* item);
};
