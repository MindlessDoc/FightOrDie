#include "item.h"

Item::Item(GraphicCell* graphicCell, QString filename)
    : _avatar(graphicCell, filename)
    , _graphicCell(graphicCell)
{

}
