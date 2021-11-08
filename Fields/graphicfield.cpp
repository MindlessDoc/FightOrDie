#include "graphicfield.h"
#include "Application/mainwindow.h"


GraphicField::GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
    : Field(heightOfCell, widthOfCell, heightInCells, widthInCells)
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
    _player = new Player(this, _entrance);
    new Enemy(this, static_cast<GraphicCell*>(_cells[5][5]));
    connect(this, &GraphicField::MovingPlayerSignal, _player, &Player::Move);
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

void GraphicField::MovingPlayerSlot(int x, int y)
{
    emit MovingPlayerSignal(x, y);
}

void GraphicField::GameOver()
{
    emit DoCloseWindow();
}
