#include "avatar.h"
#include "Cells/cell.h"

Avatar::Avatar(const Cell* cell, const QString filename, QWidget* parent)
    : QWidget(parent)
{
    _cell = cell;
    _image = QImage(filename).scaled(_cell->GetRightDownX() - _cell->GetLeftUpX(), _cell->GetRightDownY() - _cell->GetLeftUpY(), Qt::KeepAspectRatio);

    setMinimumWidth(_cell->GetRightDownX() - _cell->GetLeftUpX());
    setMinimumHeight(_cell->GetRightDownY() - _cell->GetLeftUpY());
    setMaximumWidth(_cell->GetRightDownX() - _cell->GetLeftUpX());
    setMaximumHeight(_cell->GetRightDownY() - _cell->GetLeftUpY());
}

Avatar::~Avatar()
{

}

void Avatar::Draw(QPainter* painter)
{
    painter->drawImage(_cell->GetLeftUpX(), _cell->GetLeftUpY(), _image);
}
