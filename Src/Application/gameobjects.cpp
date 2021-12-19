#include "gameobjects.h"

GameObjects::GameObjects()
{

}

GameObjects::GameObjects(Field* field, Player* player)
    : _field(field)
    , _player(player)
{

}

void GameObjects::SetField(Field *field) { _field = field; }
void GameObjects::SetPlayer(Player *player) { _player = player; }

Field* GameObjects::GetField() { return _field; }
Player* GameObjects::GetPlayer() { return _player; }
