#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include "mainwindow.h"
#include "graphicfield.h"

class Field
{
public:
    Field(int heightInCells, int widthInCells);
    ~Field();
private:
    int _heightInCells;
    int _widthInCells;
    std::shared_ptr<std::shared_ptr<Cell[]>[]> _cells;

//    Cell* _entrance;
//    Cell* _exit;

    std::shared_ptr<MainWindow> _mainWindow;
    std::shared_ptr<GraphicField> _graphicField;
};

#endif // FIELD_H
