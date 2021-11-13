#include "item.h"
#include "Cells/graphiccell.h"

Item::Item(GraphicCell* graphicCell, QString filename)
    : _avatar(graphicCell, filename)
    , _graphicCell(graphicCell)
{

}

Item::~Item()
{
    _graphicCell->_entity = nullptr;
}
