#include "deserializableplayer.h"

Serializable* DeserializablePlayer::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    int health, attack, armor;
    is >> health >> attack >> armor;
    Player* player = new Player(health, attack, armor);
    player->Init(field, cell);
    return player;
}
