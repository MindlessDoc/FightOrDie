#ifndef FIELD_H
#define FIELD_H

#include "Cells/entrance.h"
#include "Cells/exit.h"
#include "Cells/way.h"

class Field
{
public:
    Field(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    ~Field();

    Field(const Field& other);
    Field& operator=(const Field& other) = delete;

    Field(Field&& other);
    Field& operator=(Field&& other) = delete;

    int GetHeightOfCell();
    int GetWidthOfCell();

    int GetHeightInCells();
    int GetWidthInCells();


private:
    int _heightOfCell;
    int _widthOfCell;

    int _heightInCells;
    int _widthInCells;
protected:
    std::shared_ptr<std::shared_ptr<Cell[]>[]> _cells; // Will think how to make it private

//    Cell* _entrance;
//    Cell* _exit;
};

#endif // FIELD_H
