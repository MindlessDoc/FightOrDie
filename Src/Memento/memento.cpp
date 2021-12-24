#include "memento.h"

#include "Src/Fields/field.h"
#include "Src/Fields/graphicfield.h"

#include "Src/Entities/Characters/Player/player.h"

#include "Src/Entities/Characters/Enemies/virus.h"
#include "Src/Entities/Characters/Enemies/trojan.h"
#include "Src/Entities/Characters/Enemies/immortal.h"

#include "Src/Application/gameobjects.h"

Memento::Memento(std::string fileName, std::map<std::string, DeserializableFactory*>* creator)
{
    Field* field = nullptr;
    Cell* prevCell = nullptr;

    std::ifstream in(fileName);
    if(in.is_open())
    {
        std::string type;
        in >> type;
        field = static_cast<Field*>((*creator)[type]->CreateObject(in, field, prevCell, creator));
        while(!in.eof())
        {
            in >> type;
            (*creator)[type]->CreateObject(in, field, prevCell, creator);
        }
    }
    else
    {

    }
}

GameObjects* Memento::GetGameObjects() { return _gameObjects; }
