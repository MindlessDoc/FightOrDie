#pragma once

#include "Cells/cell.h"
#include "Containers/vector.h"
#include "Entities/Characters/Player/player.h"

class Field
{
public:
    Field(int heightInCells, int widthInCells);
    virtual ~Field();

    void InitField(Player* player, Mediator* mediator);

    Field(const Field& other);
    Field& operator=(const Field& other);

    Field(Field&& other);
    Field& operator=(Field&& other);

    int GetHeightInCells();
    int GetWidthInCells();

    Cell* GetCell(int column, int row);

    bool CheckOnInclusion(int column, int row);

private:
    int _heightInCells;
    int _widthInCells;

    Vector<Vector<Cell*>> _cells;
};

