#pragma once

#include "Entities/ientity.h"
#include <QString>

class Cell;

class Item : public IEntity
{
public:
    Item(Cell* cell);
    virtual ~Item();
protected:
    Cell* _cell;
};

