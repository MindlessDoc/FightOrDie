#include "graphicfield.h"
#include "Src/Application/mainwindow.h"


GraphicField::GraphicField(Field* field, int heightOfCell, int widthOfCell)
    : _field(field)
    , _heightOfCell(heightOfCell)
    , _widthOfCell(widthOfCell)
{
    _graphicCells.resize(_field->GetHeightInCells());
    for(int i = 0; i < _field->GetHeightInCells(); i++)
    {
        _graphicCells[i].resize(_field->GetWidthInCells());
        for(int j = 0; j < _field->GetWidthInCells(); j++)
        {
            _graphicCells[i][j] = _cellFactory.CreateGraphicCell(_heightOfCell, _widthOfCell,
                                                             _field->GetCell(i, j));
            //there may be a memory leak!!!!!
        }
    }
}


GraphicField::~GraphicField()
{

}

GraphicField::GraphicField(const GraphicField& other)
    : _field(other._field)
{
    _graphicCells.resize(_field->GetHeightInCells());
    for(int i = 0; i < _field->GetHeightInCells(); i++)
    {
        _graphicCells[i].resize(_field->GetWidthInCells());
        for(int j = 0; j < _field->GetWidthInCells(); j++)
        {
            _graphicCells[i][j] = _cellFactory.CreateGraphicCell(_heightOfCell, _widthOfCell,
                                                             _field->GetCell(i, j));
            //there may be a memory leak!!!!!
        }
    }
}

GraphicField& GraphicField::operator=(const GraphicField &other)
{
    if(&other == this)
        return *this;

    _heightOfCell = other._heightOfCell;
    _widthOfCell = other._widthOfCell;

    _graphicCells.resize(_field->GetHeightInCells());
    for(int i = 0; i < _field->GetHeightInCells(); i++)
    {
        _graphicCells[i].resize(_field->GetWidthInCells());
        for(int j = 0; j < _field->GetWidthInCells(); j++)
        {
            _graphicCells[i][j] = _cellFactory.CreateGraphicCell(_heightOfCell, _widthOfCell,
                                                             _field->GetCell(i, j));
            //there may be a memory leak!!!!!
        }
    }

    return *this;
}

GraphicField::GraphicField(GraphicField&& other)
    : _field(other._field)
{
    _graphicCells = other._graphicCells;
    //other._cells = nullptr; //THINK///
}

GraphicField& GraphicField::operator=(GraphicField &&other)
{
    if(&other == this)
        return *this;

    _field = other._field;

    _heightOfCell = other._heightOfCell;
    _widthOfCell = other._widthOfCell;

     _graphicCells = other._graphicCells;
    //other._cells = nullptr; //THINK///

    return *this;
}

void GraphicField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i = 0; i < _field->GetHeightInCells(); i++)
    {
        for(int j = 0; j < _field->GetWidthInCells(); j++)
        {
           _graphicCells[i][j]->DrawCell(painter);
        }
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicField::boundingRect() const
{
    //Change this
    return QRectF(-1000, -1000, 1000, 1000);
}

int GraphicField::GetHeightOfCell() { return _heightOfCell; }
int GraphicField::GetWidthOfCell() { return _widthOfCell; }

GraphicCell* GraphicField::GetGraphicCell(int column, int row)
{
    return _graphicCells[column][row];
}
