#include "field.h"

Field::Field(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
    : _heightOfCell(heightOfCell)
    , _widthOfCell(widthOfCell)
    , _heightInCells(heightInCells)
    , _widthInCells(widthInCells)
{
    _cells.resize(_heightInCells);
    // Just memory allocation
    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i].resize(_widthInCells);
    }
}

Field::~Field()
{
//    for(int i = 0; i < _heightInCells; i++)
//    {
//        delete[] _cells[i];
//    }
//    delete[] _cells;
}

Field::Field(const Field& other)
    : _heightOfCell(other._heightOfCell)
    , _widthOfCell(other._widthOfCell)
    , _heightInCells(other._heightInCells)
    , _widthInCells(other._widthInCells)
{
    _cells.resize(_heightInCells);

    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i].resize(_widthInCells);
        for(int j = 0; j < _widthInCells; j++)
        {
            _cells[i][j] = new Cell(*other._cells[i][j]);
        }
    }
}

Field& Field::operator=(const Field &other)
{
    if(&other == this)
        return *this;

    _heightOfCell = other._heightOfCell;
    _widthOfCell = other._widthOfCell;
    _heightInCells = other._heightInCells;
    _widthInCells = other._widthInCells;

    _cells.resize(_heightInCells);

    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i].resize(_widthInCells);
        for(int j = 0; j < _widthInCells; j++)
        {
            delete _cells[i][j];
            _cells[i][j] = new Cell(*other._cells[i][j]);
        }
    }

    return *this;
}

Field::Field(Field&& other)
    : _heightOfCell(other._heightOfCell)
    , _widthOfCell(other._widthOfCell)
    , _heightInCells(other._heightInCells)
    , _widthInCells(other._widthInCells)
{
    _cells = other._cells;
    //other._cells = nullptr; ///THINK///
}

Field& Field::operator=(Field&& other)
{
    if(&other == this)
        return *this;

    _heightOfCell = other._heightOfCell;
    _widthOfCell = other._widthOfCell;
    _heightInCells = other._heightInCells;
    _widthInCells = other._widthInCells;

    //delete _cells; ///THINK///

    _cells = other._cells;
    //other._cells = nullptr; ///THINK///

    return *this;
}

int Field::GetHeightOfCell() { return _heightOfCell; }
int Field::GetWidthOfCell() { return _widthOfCell; }

int Field::GetHeightInCells() { return _heightInCells; }
int Field::GetWidthInCells() { return _widthInCells; }

Cell* Field::GetCell(int column, int row) { return _cells[column][row]; }
