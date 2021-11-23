#include "field.h"

#include "Cells/entrance.h"
#include "Cells/exit.h"
#include "Cells/way.h"

Field::Field(int heightInCells, int widthInCells)
    : _heightInCells(heightInCells)
    , _widthInCells(widthInCells)
{
    //Just memory allocation
    _cells.resize(_heightInCells);
    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i].resize(_widthInCells);
    }
    //there may be a memory leak!!!!!
}

void Field::InitField(Player* player)
{
    for(int i = 0; i < _heightInCells; i++)
    {
        for(int j = 0; j < _widthInCells; j++)
        {
            if(i == 0 && j == 0)
            {
                _cells[i][j] = new Entrance(i, j);
                player->Init(this, _cells[i][j]);
            }
            else if(i == GetHeightInCells() - 1 && j == GetWidthInCells() - 1)
            {
               _cells[i][j] = new Exit(i, j);
//               _exit = static_cast<GraphicCell*>(_cells[i][j]);
//               connect(static_cast<Exit*>(_exit), &Exit::GameOver, this, &GraphicField::GameOver);
            }
            else

            {
                _cells[i][j] = new Way(i, j);
            }
        }
    }
}

Field::~Field()
{

}


//UPDATE THIS UPDATE THIS UPDATE THIS

//Field::Field(const Field& other)
//    : _heightInCells(other._heightInCells)
//    , _widthInCells(other._widthInCells)
//{
//    _cells.resize(_heightInCells);

//    for(int i = 0; i < _heightInCells; i++)
//    {
//        _cells[i].resize(_widthInCells);
//        for(int j = 0; j < _widthInCells; j++)
//        {
//            _cells[i][j] = new Cell(*other._cells[i][j]);
//        }
//    }
//}

//UPDATE THIS UPDATE THIS UPDATE THIS


//UPDATE THIS UPDATE THIS UPDATE THIS
//Field& Field::operator=(const Field &other)
//{
//    if(&other == this)
//        return *this;

//    _heightInCells = other._heightInCells;
//    _widthInCells = other._widthInCells;

//    _cells.resize(_heightInCells);

//    for(int i = 0; i < _heightInCells; i++)
//    {
//        _cells[i].resize(_widthInCells);
//        for(int j = 0; j < _widthInCells; j++)
//        {
//            delete _cells[i][j];
//            _cells[i][j] = new Cell(*other._cells[i][j]);
//        }
//    }

//    return *this;
//}
//UPDATE THIS UPDATE THIS UPDATE THIS

Field::Field(Field&& other)
    : _heightInCells(other._heightInCells)
    , _widthInCells(other._widthInCells)
{
    _cells = other._cells;
    //other._cells = nullptr; ///THINK///
}

Field& Field::operator=(Field&& other)
{
    if(&other == this)
        return *this;

    _heightInCells = other._heightInCells;
    _widthInCells = other._widthInCells;

    //delete _cells; ///THINK///

    _cells = other._cells;
    //other._cells = nullptr; ///THINK///

    return *this;
}

int Field::GetHeightInCells() { return _heightInCells; }
int Field::GetWidthInCells() { return _widthInCells; }

Cell* Field::GetCell(int column, int row) { return _cells[column][row]; }
