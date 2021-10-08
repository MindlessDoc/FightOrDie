#include "field.h"

Field::Field(int heightInCells, int widthInCells)
{
    _heightInCells = heightInCells;
    _widthInCells = widthInCells;
    _mainWindow = std::shared_ptr<MainWindow>(new MainWindow(_heightInCells * Cell::GetHeight(), _widthInCells * Cell::GetWidth()));

    _cells = std::shared_ptr<std::shared_ptr<Cell[]>[]>(new std::shared_ptr<Cell[]>[_heightInCells]);

    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i] = std::shared_ptr<Cell[]>(new Cell[_widthInCells]);
        for(int j = 0; j < _widthInCells; j++)
        {
            if(i == 0 && j == 0)
                _cells[i][j] = Cell(ENTRANCE);
            else if(i == _heightInCells -1 && j == _widthInCells - 1)
                _cells[i][j] = Cell(EXIT);
            else
                _cells[i][j] = Cell(WAY);
        }
    }

    _graphicField = std::shared_ptr<GraphicField>(new GraphicField(_heightInCells, _widthInCells, _cells));

//    _entrance = _cells[0][0];
//    _exit = _cells[_heightInCells - 1][_widthInCells - 1];

    _mainWindow->DrawField(_graphicField);
    _mainWindow->show();
}

Field::~Field()
{

}
