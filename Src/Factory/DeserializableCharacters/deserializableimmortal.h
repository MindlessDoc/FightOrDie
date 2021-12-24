#pragma once

#include "Src/Entities/Characters/Enemies/immortal.h"

class DeserializableImmortal : public DeserializableFactory
{
public:
    DeserializableImmortal() = default;
    IEntity* operator()(std::istream& is);
};
