#pragma once

#include "Cells/cell.h"
#include "Cells/graphiccell.h"

class CellFactory
{
public:
    CellFactory();
    virtual Cell* CreateCell() = 0;
    virtual GraphicCell* CreateGraphicCell() = 0;
};
