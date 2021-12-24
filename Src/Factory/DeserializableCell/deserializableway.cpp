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
        (*creator)[type]->CreateObject(is, field, nowCell, creator);
    }
    field->InitCell(coord_x, coord_y, new Way(coord_x, coord_y));
}
