#include "field.h"

Field::Field(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
    : _heightOfCell(heightOfCell)
    , _widthOfCell(widthOfCell)
    , _heightInCells(heightInCells)
    , _widthInCells(widthInCells)
{


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
}

Field::~Field()
{

}

Field::Field(const Field& other)
    : _heightOfCell(other._heightOfCell)
    , _widthOfCell(other._widthOfCell)
    , _heightInCells(other._heightInCells)
    , _widthInCells(other._widthInCells)
{
    _cells = std::shared_ptr<std::shared_ptr<Cell[]>[]>(new std::shared_ptr<Cell[]>[_heightInCells]);

    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i] = std::shared_ptr<Cell[]>(new Cell[_widthInCells]);
        for(int j = 0; j < _widthInCells; j++)
        {
                _cells[i][j] = other._cells[i][j];
        }
    }
}

Field::Field(Field&& other)
    : _heightOfCell(other._heightOfCell)
    , _widthOfCell(other._widthOfCell)
    , _heightInCells(other._heightInCells)
    , _widthInCells(other._widthInCells)
{
    _cells = other._cells;
    other._cells.reset();
}
