#include "graphicfield.h"
#include "Application/mainwindow.h"


GraphicField::GraphicField(Field* field, int heightOfCell, int widthOfCell)
    : _field(field)
    , _heightOfCell(heightOfCell)
    , _widthOfCell(widthOfCell)
{
    _graphicCells.resize(_field->GetHeightInCells());
    for(int i = 0; i < _field->GetHeightInCells(); i++)
    {
        _graphicCells[i].resize(_field->GetHeightInCells());
        for(int j = 0; j < _field->GetWidthInCells(); j++)
        {
            _graphicCells[i][j] = _cellFactory.CreateGraphicCell(_heightOfCell, _widthOfCell,
                                                             field->GetCell(i, j));
            //may be add init Enemy in Factory(in creating of graphicCell)
            //there may be a memory leak!!!!!
        }
    }
}


GraphicField::~GraphicField()
{

}

//GraphicField::GraphicField(const GraphicField& other)
//    : Field(other._heightOfCell, other._widthOfCell, other._heightInCells, other._widthInCells)
//{
//    _cells.resize(_heightInCells);

//    for(int i = 0; i < _heightInCells; i++)
//    {
//        _cells[i].resize(_widthInCells);
//        for(int j = 0; j < _widthInCells; j++)
//        {
//            _cells[i][j] = new GraphicCell(*static_cast<GraphicCell*>(other._cells[i][j]));
//        }
//    }
//}

//GraphicField& GraphicField::operator=(const GraphicField &other)
//{
//    if(&other == this)
//        return *this;

//    _heightOfCell = other._heightOfCell;
//    _widthOfCell = other._widthOfCell;
//    _heightInCells = other._heightInCells;
//    _widthInCells = other._widthInCells;

//    _cells.resize(_heightInCells);

//    for(int i = 0; i < _heightInCells; i++)
//    {
//        _cells[i].resize(_widthInCells);
//        for(int j = 0; j < _widthInCells; j++)
//        {
//            _cells[i][j] = new GraphicCell(*static_cast<GraphicCell*>(other._cells[i][j]));
//        }
//    }

//    return *this;
//}

//GraphicField::GraphicField(GraphicField&& other)
//    : Field(other._heightOfCell, other._widthOfCell, other._heightInCells, other._widthInCells)
//{
//    _cells = other._cells;
//    //other._cells = nullptr; //THINK///
//}

//GraphicField& GraphicField::operator=(GraphicField &&other)
//{
//    if(&other == this)
//        return *this;

//    _heightOfCell = other._heightOfCell;
//    _widthOfCell = other._widthOfCell;
//    _heightInCells = other._heightInCells;
//    _widthInCells = other._widthInCells;

//    _cells = other._cells;
//    //other._cells = nullptr; //THINK///

//    return *this;
//}

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
