#include "deserializablehealth.h"

Serializable* DeserializableHealth::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    return new HealthItem(cell);
}
