#pragma once

#include "Src/Cells/cell.h"
#include "Src/Fields/field.h"

class ChooseCell
{
public:
    ChooseCell() = default;
    ~ChooseCell() = default;

    virtual Cell* GetCell(Field* field) = 0;
};

