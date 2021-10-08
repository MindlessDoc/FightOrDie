#include "graphicfield.h"


GraphicField::GraphicField(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
    : Field(heightOfCell, widthOfCell, heightInCells, widthInCells)
{
    _mainWindow = std::shared_ptr<MainWindow>(new MainWindow(_heightInCells * _heightOfCell, _widthInCells * _widthOfCell));
    _mainWindow->setWindowTitle("Game field");
    _mainWindow->DrawField(this);
    _mainWindow->show();
}

void GraphicField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 1.0));
    painter->setBrush(QBrush(Qt::green));

    for(int i = 0; i < _heightInCells; i++)
    {
        for(int j = 0; j < _widthInCells; j++)
        {
            _cells[i][j].DrawCell(painter, j * _widthOfCell, i * _heightOfCell, (j + 1) * _widthOfCell, (i + 1) * _heightOfCell);
        }
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicField::boundingRect() const
{
    return QRectF(-_widthInCells, -_heightInCells, _widthInCells, _heightInCells);
}
