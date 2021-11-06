#pragma once

#include "Cells/entrance.h"
#include "Cells/exit.h"
#include "Cells/way.h"
#include "Containers/vector.h"

class Field
{
public:
    Field(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    virtual ~Field();

    Field(const Field& other);
    Field& operator=(const Field& other);

    Field(Field&& other);
    Field& operator=(Field&& other);

    int GetHeightOfCell();
    int GetWidthOfCell();

    int GetHeightInCells();
    int GetWidthInCells();

    Cell* GetCell(int column, int row);

protected:
    int _heightOfCell;
    int _widthOfCell;

    int _heightInCells;
    int _widthInCells;

    Vector<Vector<Cell*>> _cells; // Will think how to make it private

//    Cell* _entrance;
//    Cell* _exit;
};

