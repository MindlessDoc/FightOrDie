#include "avatar.h"
#include "Cells/graphiccell.h"

Avatar::Avatar(const GraphicCell* graphicCell, const QString filename, QWidget* parent)
    : QWidget(parent)
    , _width(graphicCell->GetRightDownX() - graphicCell->GetLeftUpX())
    , _height(graphicCell->GetRightDownY() - graphicCell->GetLeftUpY())
{
    _filename = filename;

    _image = QImage(filename).scaled(_width, _height, Qt::KeepAspectRatio);

    setMinimumWidth(_width);
    setMinimumHeight(_height);
    setMaximumWidth(_width);
    setMaximumHeight(_height);
}

Avatar::~Avatar()
{

}

void Avatar::Draw(const GraphicCell* cell, QPainter* painter)
{
    painter->drawImage(cell->GetLeftUpX(), cell->GetLeftUpY(), _image);
}

void Avatar::UpdatePicture(QString filename)
{
    _image = QImage(filename).scaled(_width, _height, Qt::KeepAspectRatio);

    setMinimumWidth(_width);
    setMinimumHeight(_height);
    setMaximumWidth(_width);
    setMaximumHeight(_height);
}

QString Avatar::GetFilename() const { return _filename; }
