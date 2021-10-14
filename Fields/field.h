#ifndef FIELD_H
#define FIELD_H
#include "cell.h"

class Field
{
public:
    Field(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    ~Field();

    Field(const Field& other);
    Field& operator=(const Field& other) = delete;

    Field(Field&& other);
    Field& operator=(Field&& other) = delete;


protected:
    int _heightOfCell;
    int _widthOfCell;

    int _heightInCells;
    int _widthInCells;

    std::shared_ptr<std::shared_ptr<Cell[]>[]> _cells;

//    Cell* _entrance;
//    Cell* _exit;
};

#endif // FIELD_H
