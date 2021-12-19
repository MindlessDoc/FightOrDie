#pragma once

#include "Src/Entities/ientity.h"
#include "Src/Entities/graphicentity.h"
#include "Src/Entities/Characters/Player/player.h"
#include "Src/Entities/Characters/Enemies/virus.h"
#include "Src/Entities/Characters/Enemies/trojan.h"
#include "Src/Entities/Characters/Enemies/immortal.h"
#include "Src/Entities/Items/HealthItem/healthitem.h"
#include "Src/Entities/Items/ArmorItem/armoritem.h"
#include "Src/Entities/Items/AttackItem/attackitem.h"


class EntityFactory
{
public:
    EntityFactory();

    //virtual IEntity* CreateEntity();
    virtual GraphicEntity* CreateGraphicEntity(IEntity* _entity, const GraphicCell* graphicCell);
};
