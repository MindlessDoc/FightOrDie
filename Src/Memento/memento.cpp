#include "memento.h"

#include "Src/Fields/field.h"
#include "Src/Fields/graphicfield.h"

#include "Src/Entities/Characters/Player/player.h"

#include "Src/Entities/Characters/Enemies/virus.h"
#include "Src/Entities/Characters/Enemies/trojan.h"
#include "Src/Entities/Characters/Enemies/immortal.h"

#include "Src/Application/gameobjects.h"

Memento::Memento(std::ifstream& in, std::map<std::string, DeserializableFactory*>* creator)
{
    Field* field = nullptr;
    Cell* prevCell = nullptr;

    if(in.is_open())
    {
        try
        {
            std::string type;
            in >> type;
            if(type != typeid (Field).name())
            {
                _gameObjects = nullptr;
                throw std::exception();
                return;
            }
            else
            {
                field = static_cast<Field*>((*creator)[type]->CreateObject(in, field, prevCell, creator));
                while(!in.eof())
                {
                    in >> type;
                    if(creator->count(type) == 0)
                        throw std::exception();
                    else
                        (*creator)[type]->CreateObject(in, field, prevCell, creator);
                }
                _gameObjects = new GameObjects(field, nullptr);
            }
        }
        catch (std::exception& ex)
        {
            std::cout << "Error";
            delete field;
            _gameObjects = nullptr;
        }

    }
    else
    {

    }

}

GameObjects* Memento::GetGameObjects() { return _gameObjects; }
