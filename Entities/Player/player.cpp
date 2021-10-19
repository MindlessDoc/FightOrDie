#include "player.h"

Player::Player(const Cell* cell)
    : _avatar(cell, "C:/QtProjects/OOP/FightOrDie/Src/XYZ.png")
{

}

void Player::Draw(QPainter* painter)
{
    _avatar.Draw(painter);
}
