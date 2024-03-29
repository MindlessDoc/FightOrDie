#include "deserializableplayer.h"

Serializable* DeserializablePlayer::CreateObject(std::istream& is, Field* field, Cell* cell,
                                                 std::map<std::string, DeserializableFactory*>* creator)
{
    int health, attack, armor;
    is >> health >> attack >> armor;
    if(health == 0 || attack == 0 || armor == 0)
        throw std::exception();
    else
    {
        Player* player = new Player(health, attack, armor);
        player->Init(field, cell);
        return player;
    }
}
