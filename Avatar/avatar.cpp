#include "avatar.h"
#include "Cells/graphiccell.h"

Avatar::Avatar(const GraphicCell* graphicCell, const QString filename, QWidget* parent)
    : QWidget(parent)
{
    _image = QImage(filename).scaled(graphicCell->GetRightDownX() - graphicCell->GetLeftUpX(), graphicCell->GetRightDownY() - graphicCell->GetLeftUpY(), Qt::KeepAspectRatio);

    setMinimumWidth(graphicCell->GetRightDownX() - graphicCell->GetLeftUpX());
    setMinimumHeight(graphicCell->GetRightDownY() - graphicCell->GetLeftUpY());
    setMaximumWidth(graphicCell->GetRightDownX() - graphicCell->GetLeftUpX());
    setMaximumHeight(graphicCell->GetRightDownY() - graphicCell->GetLeftUpY());
}

Avatar::~Avatar()
{

}

void Avatar::Draw(const GraphicCell* graphicCell, QPainter* painter)
{
    painter->drawImage(graphicCell->GetLeftUpX(), graphicCell->GetLeftUpY(), _image);
}
