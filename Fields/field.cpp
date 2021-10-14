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
                _cells[i][j] = Entrance(j * _widthOfCell, i * _heightOfCell, (j + 1) * _widthOfCell, (i + 1) * _heightOfCell);
            else if(i == _heightInCells - 1 && j == _widthInCells - 1)
                _cells[i][j] = Exit(j * _widthOfCell, i * _heightOfCell, (j + 1) * _widthOfCell, (i + 1) * _heightOfCell);
            else
                _cells[i][j] = Way(j * _widthOfCell, i * _heightOfCell, (j + 1) * _widthOfCell, (i + 1) * _heightOfCell);
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
                _cells[i][j] = other._cells[i][j]; // Add copy-inicialization constructor
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

int Field::GetHeightOfCell() { return _heightOfCell; }
int Field::GetWidthOfCell() { return _widthOfCell; }

int Field::GetHeightInCells() { return _heightInCells; }
int Field::GetWidthInCells() { return _widthInCells; }
