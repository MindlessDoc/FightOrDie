#include "player.h"

Player::Player(Cell* cell)
    : _avatar(cell, "C:/QtProjects/OOP/FightOrDie/Src/Player.png")
{
    _cell = cell;
}

void Player::Draw(QPainter* painter)
{
    _avatar.Draw(_cell, painter);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    switch (key)
    {
    case Qt::Key_W:
        break;
    }
}
