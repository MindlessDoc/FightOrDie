#pragma once

#include "Entities/ientity.h"

class Cell;
class Field;

class ICharacter : public IEntity
{
public:
    virtual ~ICharacter() = default;
};
