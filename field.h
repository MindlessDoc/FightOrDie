#ifndef FIELD_H
#define FIELD_H
#include "cell.h"
#include "mainwindow.h"
#include "graphicfield.h"

class Field
{
public:
    Field(int heightInCells, int widthInCells);
private:
    int _heightInCells;
    int _widthInCells;
    Cell*** _cells;
    MainWindow* _mainWindow;
    GraphicField* _graphicField;
};

#endif // FIELD_H
