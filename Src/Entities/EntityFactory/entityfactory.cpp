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
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/Immortal.png");
    }
    else if(typeid(*entity) == typeid(Trojan))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/Trojan.png");
    }
    else if(typeid(*entity) == typeid(Virus))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/Virus.png");
    }
    else if(typeid(*entity) == typeid(Player))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/Player.png");
    }
    else if(typeid(*entity) == typeid(ArmorItem))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/Antivirus.png");
    }
    else if(typeid(*entity) == typeid(AttackItem))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/ZeroGun.png");
    }
    else if(typeid(*entity) == typeid(HealthItem))
    {
        return new GraphicEntity(entity, graphicCell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/AidKit.png");
    }
}
