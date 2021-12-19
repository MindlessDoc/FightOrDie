#include "cellfactory.h"

#include "Src/Cells/way.h"
#include "Src/Cells/exit.h"
#include "Src/Cells/entrance.h"

#include <iostream>

CellFactory::CellFactory()
{

}

//Cell* CellFactory::CreateCell()
//{

//}

GraphicCell* CellFactory::CreateGraphicCell(int heightOfCell, int widthOfCell, Cell* cell)
{
    if(typeid (*cell) == typeid (Entrance))
    {
        return new GraphicCell(cell->GetRow() * widthOfCell, cell->GetColumn() * heightOfCell,
                                                  (cell->GetRow() + 1) * widthOfCell, (cell->GetColumn() + 1) * heightOfCell,
                                                  cell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/Door.png");
    }
    else if(typeid (*cell) == typeid (Exit))
    {
        return new GraphicCell(cell->GetRow() * widthOfCell, cell->GetColumn() * heightOfCell,
                               (cell->GetRow() + 1) * widthOfCell, (cell->GetColumn() + 1) * heightOfCell,
                               cell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/Portal.png");
    }
    else if(typeid (*cell) == typeid (Way))
    {
        return new GraphicCell(cell->GetRow() * widthOfCell, cell->GetColumn() * heightOfCell,
                               (cell->GetRow() + 1) * widthOfCell, (cell->GetColumn() + 1) * heightOfCell,
                               cell, "C:/QtProjects/OOP/FightOrDie/Resources/Src/Way.png");
    }
}
