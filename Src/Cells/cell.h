#pragma once

#include"Src/Entities/ientity.h"

#include<memory>
#include<iostream>

class Mediator;

class Cell
{
public:
    Cell(int column, int row, Mediator* mediator);
    Cell() = default;
    virtual ~Cell();

    Cell(const Cell& other);
    Cell& operator= (const Cell& other);

    int GetColumn() const;
    int GetRow() const;

    virtual void Moving(Cell* swapCell);

    IEntity* GetEntity();
    void SetEntity(IEntity* entity);

    virtual bool CanMoveIn(const IEntity* entity) = 0;

protected:
    Mediator* _mediator;

private:
    int _column, _row;
    IEntity* _entity;
};
