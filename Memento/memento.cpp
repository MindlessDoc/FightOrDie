#include "memento.h"

#include "Fields/field.h"
#include "Fields/graphicfield.h"

#include "Entities/Characters/Player/player.h"

#include "Entities/Characters/Enemies/virus.h"
#include "Entities/Characters/Enemies/trojan.h"
#include "Entities/Characters/Enemies/immortal.h"

#include "Application/gameobjects.h"

Memento::Memento(std::string fileName)
{

}

GameObjects* Memento::GetGameObjects() { return _gameObjects; }
