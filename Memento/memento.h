#pragma once
#include <string>

class GameObjects;

class Memento
{
public:
    Memento(std::string fileName);

    GameObjects* GetGameObjects();

private:
    GameObjects* _gameObjects;
};

