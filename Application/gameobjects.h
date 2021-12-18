#pragma once

#include "Fields/graphicfield.h"

class GameObjects
{
public:
    GameObjects();
    GameObjects(Field* field, Player* player);

    virtual ~GameObjects() = default;

    void SetField(Field* field);
    void SetPlayer(Player* player);

    Field* GetField();
    Player* GetPlayer();


private:
    Field* _field;
    Player* _player;
};
