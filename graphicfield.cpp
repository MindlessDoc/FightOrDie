#include "graphicfield.h"

GraphicField::GraphicField(int heightInCells, int widthInCells)
{
    _heightInCells = heightInCells;
    _widthInCells = widthInCells;
}

void GraphicField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int heightCell = Cell::GetHeight();
    int widthCell = Cell::GetWidth();

    painter->setPen(QPen(Qt::black, 1.0));
    painter->setBrush(QBrush(Qt::green));

    for(int i = 0; i < _heightInCells; i++)
    {
        for(int j = 0; j < _widthInCells; j++)
        {
            painter->drawRect(j * widthCell, i * heightCell, (j + 1) * widthCell, (i + 1) * heightCell);
        }
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicField::boundingRect() const
{
    return QRectF(-_widthInCells, -_heightInCells, _widthInCells, _heightInCells);
}
