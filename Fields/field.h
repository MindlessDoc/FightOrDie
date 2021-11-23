#pragma once

#include "Cells/cell.h"
#include "Containers/vector.h"
#include "Entities/Characters/Player/player.h"

class Field
{
public:
    Field(int heightInCells, int widthInCells);
    virtual ~Field();

    void InitField(Player* player);

    Field(const Field& other);
    Field& operator=(const Field& other);

    Field(Field&& other);
    Field& operator=(Field&& other);

    int GetHeightInCells();
    int GetWidthInCells();

    Cell* GetCell(int column, int row);

protected:
    int _heightInCells;
    int _widthInCells;

    Vector<Vector<Cell*>> _cells; // Will think how to make it private
};

