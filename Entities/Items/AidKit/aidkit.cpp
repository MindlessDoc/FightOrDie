#include "aidkit.h"
#include "Cells/graphiccell.h"

AidKit::AidKit(GraphicCell* graphicCell)
    : Item(graphicCell, "C:/QtProjects/OOP/FightOrDie/Src/AidKit.png")
{
    _graphicCell->_entity = this;
}

AidKit::~AidKit()
{
    _graphicCell->_entity = nullptr;
}

void AidKit::Draw(QPainter* painter)
{
    _avatar.Draw(_graphicCell, painter);
}

int AidKit::Type()
{
    return IEntity::AIDKIT;
}

int AidKit::GetHealthPointers() { return _healthPointers; }
