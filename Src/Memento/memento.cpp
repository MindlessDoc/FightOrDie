#include "memento.h"

#include "Src/Fields/field.h"
#include "Src/Fields/graphicfield.h"

#include "Src/Entities/Characters/Player/player.h"

#include "Src/Entities/Characters/Enemies/virus.h"
#include "Src/Entities/Characters/Enemies/trojan.h"
#include "Src/Entities/Characters/Enemies/immortal.h"

#include "Src/Application/gameobjects.h"

Memento::Memento(std::string fileName)
{

}

GameObjects* Memento::GetGameObjects() { return _gameObjects; }
