#pragma once
#include <string>
#include <fstream>
#include <map>
#include "Src/Factory/deserializablefactory.h"

class GameObjects;

class Memento
{
public:
    Memento(std::string fileName, std::map<std::string, DeserializableFactory> creator);

    GameObjects* GetGameObjects();

private:
    GameObjects* _gameObjects;
};

