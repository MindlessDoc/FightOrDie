#include "deserializablehealth.h"

Serializable* DeserializableHealth::CreateObject(std::istream& is, Field* field, Cell* cell,
                                                 std::map<std::string, DeserializableFactory*>* creator)
{
    return new HealthItem(cell);
}
