#include "cellfactory.h"

#include "Cells/way.h"
#include "Cells/exit.h"
#include "Cells/entrance.h"

CellFactory::CellFactory()
{

}

//Cell* CellFactory::CreateCell()
//{

//}

GraphicCell* CellFactory::CreateGraphicCell(int heightOfCell, int widthOfCell, Cell* cell)
{
    if(typeid (cell) == typeid (Entrance))
    {
        return new GraphicCell(cell->GetRow() * widthOfCell, cell->GetColumn() * heightOfCell,
                               (cell->GetRow() + 1) * widthOfCell, (cell->GetColumn() + 1) * heightOfCell,
                               cell, "C:/QtProjects/OOP/FightOrDie/Src/Door.png");
    }
    else if(typeid (cell) == typeid (Exit))
    {
        return new GraphicCell(cell->GetRow() * widthOfCell, cell->GetColumn() * heightOfCell,
                               (cell->GetRow() + 1) * widthOfCell, (cell->GetColumn() + 1) * heightOfCell,
                               cell, "C:/QtProjects/OOP/FightOrDie/Src/Portal.png");
    }
    else if(typeid (cell) == typeid (Way))
    {
        return new GraphicCell(cell->GetRow() * widthOfCell, cell->GetColumn() * heightOfCell,
                               (cell->GetRow() + 1) * widthOfCell, (cell->GetColumn() + 1) * heightOfCell,
                               cell, "C:/QtProjects/OOP/FightOrDie/Src/Way.png");
    }
}
