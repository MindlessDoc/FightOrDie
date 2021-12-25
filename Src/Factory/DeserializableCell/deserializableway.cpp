#include "deserializableway.h"
#include "Src/Fields/field.h"

Serializable* DeserializableWay::CreateObject(std::istream& is, Field* field, Cell* cell,
                                              std::map<std::string, DeserializableFactory*>* creator)
{
    int coord_x, coord_y;
    is >> coord_x >> coord_y;
    Cell* nowCell = new Way(coord_x, coord_y);
    std::string type;
    is >> type;
    if(type != "Nullptr")
    {
        if(creator->count(type) == 0 || coord_x < 0 || coord_y < 0
                || coord_x >= field->GetHeightInCells() || coord_y >= field->GetWidthInCells())
            throw std::exception();
        else
        {
            creator->operator[](type)->CreateObject(is, field, nowCell, creator);
        }
    }
    field->InitCell(coord_x, coord_y, nowCell);
}
