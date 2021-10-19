#include "avatar.h"
#include "Cells/cell.h"

Avatar::Avatar(const Cell* cell, const QString filename, QWidget* parent)
    : QWidget(parent)
{
    _image = QImage(filename).scaled(cell->GetRightDownX() - cell->GetLeftUpX(), cell->GetRightDownY() - cell->GetLeftUpY(), Qt::KeepAspectRatio);

    setMinimumWidth(cell->GetRightDownX() - cell->GetLeftUpX());
    setMinimumHeight(cell->GetRightDownY() - cell->GetLeftUpY());
    setMaximumWidth(cell->GetRightDownX() - cell->GetLeftUpX());
    setMaximumHeight(cell->GetRightDownY() - cell->GetLeftUpY());
}

Avatar::~Avatar()
{

}

void Avatar::Draw(const Cell* cell, QPainter* painter)
{
    painter->drawImage(cell->GetLeftUpX(), cell->GetLeftUpY(), _image);
}
