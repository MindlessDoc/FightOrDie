#pragma once

#include "Entities/ientity.h"
#include "Entities/graphicentity.h"
#include "Entities/Characters/Player/player.h"
#include "Entities/Characters/Enemies/virus.h"
#include "Entities/Characters/Enemies/trojan.h"
#include "Entities/Characters/Enemies/immortal.h"
#include "Entities/Items/HealthItem/healthitem.h"
#include "Entities/Items/ArmorItem/armoritem.h"
#include "Entities/Items/AttackItem/attackitem.h"


class EntityFactory
{
public:
    EntityFactory();

    virtual IEntity* CreateEntity();
    virtual GraphicEntity* CreateGraphicEntity();
};
