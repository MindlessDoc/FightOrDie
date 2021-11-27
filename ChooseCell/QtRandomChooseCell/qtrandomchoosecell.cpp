#include "qtrandomchoosecell.h"

#include <QRandomGenerator>
#include "Cells/way.h"

Cell* QtRandomChooseCell::GetCell(Field *field)
{
    int column = QRandomGenerator::global()->bounded(0, field->GetHeightInCells());
    int row = QRandomGenerator::global()->bounded(0, field->GetWidthInCells());
    while(typeid(*(field->GetCell(column, row))) != typeid (Way) && !field->GetCell(column, row)->GetEntity())
    {
        column = QRandomGenerator::global()->bounded(0, field->GetHeightInCells());
        row = QRandomGenerator::global()->bounded(0, field->GetWidthInCells());
    }

    return field->GetCell(column, row);
}
