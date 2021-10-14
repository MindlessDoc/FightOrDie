#include "graphicfield.h"


GraphicField::GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
    : Field(heightOfCell, widthOfCell, heightInCells, widthInCells)
{
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
    painter->setPen(QPen(Qt::black, 1.0));
    painter->setBrush(QBrush(Qt::green));

    for(int i = 0; i < GetHeightInCells(); i++)
    {
        for(int j = 0; j < GetWidthInCells(); j++)
        {
            _cells[i][j].DrawCell(painter);
        }
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicField::boundingRect() const
{
    return QRectF(-1000, -1000, 1000, 1000);
}
