#pragma once
#include <string>
#include <fstream>
#include <map>
#include "Src/Factory/deserializablefactory.h"

class GameObjects;

class Memento
{
public:
    Memento(std::ifstream& in, std::map<std::string, DeserializableFactory*>* creator);

    GameObjects* GetGameObjects();

private:
    GameObjects* _gameObjects = nullptr;
};

