#include "graphicfield.h"


GraphicField::GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
    : Field(heightOfCell, widthOfCell, heightInCells, widthInCells)
{
    for(int i = 0; i < GetHeightInCells(); i++)
    {
        for(int j = 0; j < GetWidthInCells(); j++)
        {
            if(i == 0 && j == 0)
                _cells[i][j] = new Entrance(j * GetWidthOfCell(), i * GetHeightOfCell(), (j + 1) * GetWidthOfCell(), (i + 1) * GetHeightOfCell());
            else if(i == GetHeightInCells() - 1 && j == GetWidthInCells() - 1)
                _cells[i][j] = new Exit(j * GetWidthOfCell(), i * GetHeightOfCell(), (j + 1) * GetWidthOfCell(), (i + 1) * GetHeightOfCell());
            else
                _cells[i][j] = new Way(j * GetWidthOfCell(), i * GetHeightOfCell(), (j + 1) * GetWidthOfCell(), (i + 1) * GetHeightOfCell());
        }
    }

    _mainWindow = std::shared_ptr<MainWindow>(new MainWindow(GetHeightInCells() * GetHeightOfCell(), GetWidthInCells() * GetWidthOfCell()));
    _mainWindow->setWindowTitle("Game field");
    _mainWindow->DrawField(this);
    _mainWindow->show();
}
GraphicField::~GraphicField()
{

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
