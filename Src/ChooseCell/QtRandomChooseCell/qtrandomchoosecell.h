#pragma once

#include "Src/ChooseCell/choosecell.h"

class QtRandomChooseCell : public ChooseCell
{
public:
    QtRandomChooseCell() = default;
    virtual ~QtRandomChooseCell() = default;

    virtual Cell* GetCell(Field* field) override;
};
