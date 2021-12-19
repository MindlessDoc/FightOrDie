#pragma once

#include "Src/Entities/ientity.h"
#include <QString>

class Cell;
class Mediator;

class Item : public IEntity
{
public:
    Item(Cell* cell);
    Item(Cell* cell, Mediator* mediator);
    virtual ~Item();

    virtual std::string LogOut() const override;
    void SetMediator(Mediator* mediator);

protected:
    Cell* _cell;

    Mediator* _mediator;
};

