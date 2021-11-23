#pragma once

#include "../cellfactory.h"

class QtExitCellFactory : public CellFactory
{
public:
    QtExitCellFactory();
    virtual Cell* CreateCell();
    virtual GraphicCell* CreateGraphicCell();
};

