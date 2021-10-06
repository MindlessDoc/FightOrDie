#include "field.h"

Field::Field(int heightInCells, int widthInCells)
{
    _heightInCells = heightInCells;
    _widthInCells = widthInCells;
    _mainWindow = new MainWindow(_heightInCells * Cell::GetHeight(), _widthInCells * Cell::GetWidth());
    _graphicField = new GraphicField(_heightInCells, _widthInCells);


    _cells = new Cell** [_heightInCells];
    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i] = new Cell* [_widthInCells];
        for(int j = 0; j < _widthInCells; j++)
        {
            _cells[i][j] = new Cell(true);
        }
    }
    _mainWindow->DrawField(_graphicField);
    _mainWindow->show();
}
