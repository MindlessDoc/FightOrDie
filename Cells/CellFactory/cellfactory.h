#pragma once

#include "Cells/cell.h"
#include "Cells/graphiccell.h"

class CellFactory
{
public:
    CellFactory();
    //virtual Cell* CreateCell();
    virtual GraphicCell* CreateGraphicCell(int heightOfCell, int widthOfCell, Cell* cell);
};
