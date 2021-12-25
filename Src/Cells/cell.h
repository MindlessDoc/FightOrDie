#pragma once

#include"Src/Entities/ientity.h"

#include<memory>
#include<iostream>

class Mediator;

class Cell : public Serializable
{
public:
    Cell(int column, int row);
    Cell(int column, int row, Mediator* mediator);
    Cell();
    virtual ~Cell();

    Cell(const Cell& other);
    Cell& operator= (const Cell& other);

    int GetColumn() const;
    int GetRow() const;

    virtual void Moving(Cell* swapCell);

    IEntity* GetEntity();
    void SetEntity(IEntity* entity);

    virtual bool CanMoveIn(const IEntity* entity) = 0;

    void InitMediator(Mediator* mediator);

protected:
    Mediator* _mediator = nullptr;

private:
    int _column = 0, _row = 0;
    IEntity* _entity = nullptr;
};
