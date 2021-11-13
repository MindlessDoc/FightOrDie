#include "graphicfield.h"
#include "Application/mainwindow.h"


GraphicField::GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
    : Field(heightOfCell, widthOfCell, heightInCells, widthInCells)
{

}

void GraphicField::InitGraphicField(Player *player)
{
    for(int i = 0; i < GetHeightInCells(); i++)
    {
        for(int j = 0; j < GetWidthInCells(); j++)
        {
            if(i == 0 && j == 0)
            {
                _cells[i][j] = new Entrance(j * GetWidthOfCell(), i * GetHeightOfCell(), (j + 1) * GetWidthOfCell(),
                                            (i + 1) * GetHeightOfCell(), i, j);
                _entrance = static_cast<GraphicCell*>(_cells[i][j]);
                player->Init(this, _entrance);
            }
            else if(i == GetHeightInCells() - 1 && j == GetWidthInCells() - 1)
            {
               _cells[i][j] = new Exit(j * GetWidthOfCell(), i * GetHeightOfCell(),
                                       (j + 1) * GetWidthOfCell(), (i + 1) * GetHeightOfCell(), i, j);
               _exit = static_cast<GraphicCell*>(_cells[i][j]);
               connect(static_cast<Exit*>(_exit), &Exit::GameOver, this, &GraphicField::GameOver);
            }
            else

            {
                _cells[i][j] = new Way(j * GetWidthOfCell(), i * GetHeightOfCell(),
                                       (j + 1) * GetWidthOfCell(), (i + 1) * GetHeightOfCell(), i, j);
            }
        }
    }
    new HealthItem(static_cast<GraphicCell*>(_cells[4][4])); //FIX
    new AttackItem(static_cast<GraphicCell*>(_cells[4][5])); //FIX
    new ArmorItem(static_cast<GraphicCell*>(_cells[4][6])); //FIX

    new Virus(this, static_cast<GraphicCell*>(_cells[0][1])); //FIX
    new Virus(this, static_cast<GraphicCell*>(_cells[0][2])); //FIX
    new Virus(this, static_cast<GraphicCell*>(_cells[0][3])); //FIX
    new Virus(this, static_cast<GraphicCell*>(_cells[0][4])); //FIX
    new Virus(this, static_cast<GraphicCell*>(_cells[0][5])); //FIX

    new Immortal(this, static_cast<GraphicCell*>(_cells[2][1])); //FIX
    new Immortal(this, static_cast<GraphicCell*>(_cells[2][2])); //FIX
    new Immortal(this, static_cast<GraphicCell*>(_cells[2][3])); //FIX
    new Immortal(this, static_cast<GraphicCell*>(_cells[2][4])); //FIX
    new Immortal(this, static_cast<GraphicCell*>(_cells[2][5])); //FIX

    new Trojan(this, static_cast<GraphicCell*>(_cells[1][1])); //FIX
    new Trojan(this, static_cast<GraphicCell*>(_cells[1][2])); //FIX
    new Trojan(this, static_cast<GraphicCell*>(_cells[1][3])); //FIX
    new Trojan(this, static_cast<GraphicCell*>(_cells[1][4])); //FIX
    new Trojan(this, static_cast<GraphicCell*>(_cells[1][5])); //FIX

    connect(player, &Player::GameOver, this, &GraphicField::GameOver);
}

GraphicField::~GraphicField()
{

}

GraphicField::GraphicField(const GraphicField& other)
    : Field(other._heightOfCell, other._widthOfCell, other._heightInCells, other._widthInCells)
{
    _cells.resize(_heightInCells);

    for(int i = 0; i < _heightInCells; i++)
    {
        _cells[i].resize(_widthInCells);
        for(int j = 0; j < _widthInCells; j++)
        {
            _cells[i][j] = new GraphicCell(*static_cast<GraphicCell*>(other._cells[i][j]));
        }
    }
}

GraphicField& GraphicField::operator=(const GraphicField &other)
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
            _cells[i][j] = new GraphicCell(*static_cast<GraphicCell*>(other._cells[i][j]));
        }
    }

    return *this;
}

GraphicField::GraphicField(GraphicField&& other)
    : Field(other._heightOfCell, other._widthOfCell, other._heightInCells, other._widthInCells)
{
    _cells = other._cells;
    //other._cells = nullptr; //THINK///
}

GraphicField& GraphicField::operator=(GraphicField &&other)
{
    if(&other == this)
        return *this;

    _heightOfCell = other._heightOfCell;
    _widthOfCell = other._widthOfCell;
    _heightInCells = other._heightInCells;
    _widthInCells = other._widthInCells;

    _cells = other._cells;
    //other._cells = nullptr; //THINK///

    return *this;
}

void GraphicField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i = 0; i < GetHeightInCells(); i++)
    {
        for(int j = 0; j < GetWidthInCells(); j++)
        {
            static_cast<GraphicCell*>(_cells[i][j])->DrawCell(painter);
        }
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicField::boundingRect() const
{
    return QRectF(-1000, -1000, 1000, 1000);
}

void GraphicField::GameOver()
{
    emit DoCloseWindow();
}
