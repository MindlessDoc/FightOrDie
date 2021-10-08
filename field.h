#ifndef FIELD_H
#define FIELD_H
#include "cell.h"

class Field
{
public:
    Field(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    ~Field();
protected:
    const int _heightOfCell;
    const int _widthOfCell;

    const int _heightInCells;
    const int _widthInCells;

    std::shared_ptr<std::shared_ptr<Cell[]>[]> _cells;

//    Cell* _entrance;
//    Cell* _exit;
};

#endif // FIELD_H
