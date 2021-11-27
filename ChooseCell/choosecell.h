#pragma once

#include "Cells/cell.h"
#include "Fields/field.h"

class ChooseCell
{
public:
    ChooseCell() = default;
    ~ChooseCell() = default;

    virtual Cell* GetCell(Field* field) = 0;
};

