#pragma once

#include "Src/Cells/cell.h"
#include "Src/Cells/graphiccell.h"

class CellFactory
{
public:
    CellFactory();
    //virtual Cell* CreateCell();
    virtual GraphicCell* CreateGraphicCell(int heightOfCell, int widthOfCell, Cell* cell);
};
