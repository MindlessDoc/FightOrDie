#include "entityfactory.h"

EntityFactory::EntityFactory()
{

}

GraphicEntity* EntityFactory::CreateGraphicEntity(IEntity* entity, const GraphicCell* graphicCell)
{
    if(!entity)
        return nullptr;
    if(typeid(*entity) == typeid(Immortal))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Immortal.png");
    }
    else if(typeid(*entity) == typeid(Trojan))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Trojan.png");
    }
    else if(typeid(*entity) == typeid(Virus))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Virus.png");
    }
    else if(typeid(*entity) == typeid(Player))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Player.png");
    }
    else if(typeid(*entity) == typeid(ArmorItem))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/Antivirus.png");
    }
    else if(typeid(*entity) == typeid(AttackItem))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/ZeroGun.png");
    }
    else if(typeid(*entity) == typeid(HealthItem))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/AidKit.png");
    }
}
