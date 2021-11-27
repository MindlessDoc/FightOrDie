#include "field.h"

#include "Cells/entrance.h"
#include "Cells/exit.h"
#include "Cells/way.h"

#include "Entities/ientity.h"
#include "Entities/graphicentity.h"
#include "Entities/Characters/Player/player.h"

#include "Entities/Items/HealthItem/healthitem.h"
#include "Entities/Items/ArmorItem/armoritem.h"
#include "Entities/Items/AttackItem/attackitem.h"

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

void Field::InitField(Player* player, Mediator* mediator)
{
    for(int i = 0; i < _heightInCells; i++)
    {
        for(int j = 0; j < _widthInCells; j++)
        {
            if(i == 0 && j == 0)
            {
                _cells[i][j] = new Entrance(i, j, mediator);
                player->Init(this, _cells[i][j]);
            }
            else if(i == GetHeightInCells() - 1 && j == GetWidthInCells() - 1)
            {
               _cells[i][j] = new Exit(i, j, mediator);
            }
            else
            {
                _cells[i][j] = new Way(i, j, mediator);
            }
        }
    }

    new HealthItem(_cells[0][1], mediator);
    new AttackItem(_cells[0][2], mediator);
    new ArmorItem(_cells[0][3], mediator);
    new ArmorItem(_cells[1][5], mediator);

//    new Virus(this, _cells[0][4], mediator);
//    new Virus(this, _cells[3][1], mediator);
//    new Virus(this, _cells[3][2], mediator);
//    new Virus(this, _cells[3][3], mediator);
//    new Virus(this, _cells[3][4], mediator);

//    new Immortal(this, _cells[4][1], mediator);
//    new Immortal(this, _cells[4][2], mediator);
//    new Immortal(this, _cells[4][3], mediator);
//    new Immortal(this, _cells[4][4], mediator);

//    new Trojan(this, _cells[5][1], mediator);
//    new Trojan(this, _cells[5][2], mediator);
//    new Trojan(this, _cells[5][3], mediator);
//    new Trojan(this, _cells[5][4], mediator);

//    new Trojan(this, _cells[0][6], mediator);
}

Field::~Field()
{

}


Field::Field(const Field& other)
    : _heightInCells(other._heightInCells)
    , _widthInCells(other._widthInCells)
{
    _cells.resize(_heightInCells);

    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i].resize(_widthInCells);
    }
}



Field& Field::operator=(const Field &other)
{
    if(&other == this)
        return *this;

    _heightInCells = other._heightInCells;
    _widthInCells = other._widthInCells;

    _cells.resize(_heightInCells);

    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i].resize(_widthInCells);
    }

    return *this;
}

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

bool Field::CheckOnInclusion(int column, int row)
{
    if(column >= 0 && row >= 0 && column < _heightInCells && row < _widthInCells)
    {
        return true;
    }
    else
    {
        return false;
    }
}
