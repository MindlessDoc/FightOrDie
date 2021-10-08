#include "field.h"

Field::Field(int heightInCells, int widthInCells)
{
    _heightInCells = heightInCells;
    _widthInCells = widthInCells;
    _mainWindow = new MainWindow(_heightInCells * Cell::GetHeight(), _widthInCells * Cell::GetWidth());

    _cells = new Cell** [_heightInCells];

    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i] = new Cell* [_widthInCells];
        for(int j = 0; j < _widthInCells; j++)
        {
            if(i == 0 && j == 0)
                _cells[i][j] = new Cell(ENTRANCE);
            else if(i == _heightInCells -1 && j == _widthInCells - 1)
                _cells[i][j] = new Cell(EXIT);
            else
                _cells[i][j] = new Cell(WAY);
        }
    }

    _graphicField = new GraphicField(_heightInCells, _widthInCells, _cells);

//    _entrance = _cells[0][0];
//    _exit = _cells[_heightInCells - 1][_widthInCells - 1];

    _mainWindow->DrawField(_graphicField);
    _mainWindow->show();
}

Field::~Field()
{
    delete _graphicField;
    delete _mainWindow;


    for(int i = 0; i < _heightInCells; i++)
    {
        delete[] _cells[i];
    }
    delete[] _cells;
}
