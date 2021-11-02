#include "graphicfield.h"


GraphicField::GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
    : Field(heightOfCell, widthOfCell, heightInCells, widthInCells)
{
    for(int i = 0; i < GetHeightInCells(); i++)
    {
        for(int j = 0; j < GetWidthInCells(); j++)
        {
            if(i == 0 && j == 0)
                _cells[i][j] = std::make_shared<GraphicCell>(new Entrance(j * GetWidthOfCell(), i * GetHeightOfCell(), (j + 1) * GetWidthOfCell(), (i + 1) * GetHeightOfCell(), i, j));
            else if(i == GetHeightInCells() - 1 && j == GetWidthInCells() - 1)
                _cells[i][j] = std::make_shared<GraphicCell>(new Exit(j * GetWidthOfCell(), i * GetHeightOfCell(), (j + 1) * GetWidthOfCell(), (i + 1) * GetHeightOfCell(), i, j));
            else
                _cells[i][j] = std::make_shared<GraphicCell>(new Way(j * GetWidthOfCell(), i * GetHeightOfCell(), (j + 1) * GetWidthOfCell(), (i + 1) * GetHeightOfCell(), i, j));
            _cells[i][j]->_item = nullptr;
        }
    }
    _player = new Player(static_cast<GraphicCell*>(_cells[0][0].get()));
    connect(this, &GraphicField::MovingItemCells, _player, &Player::MovingItemCells);
    _cells[0][0]->_item = _player;
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
            _cells[i][j] = std::make_shared<GraphicCell>(other._cells[i][j]);
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
            _cells[i][j] = std::make_shared<GraphicCell>(other._cells[i][j]);
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
            static_cast<GraphicCell*>(_cells[i][j].get())->DrawCell(painter);
        }
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicField::boundingRect() const
{
    return QRectF(-1000, -1000, 1000, 1000);
}

void GraphicField::MovingPlayer(int x, int y)
{
    emit MovingItemCells(x, y, _cells);
}
