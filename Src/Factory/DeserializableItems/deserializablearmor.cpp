#include "deserializablearmor.h"

Serializable* DeserializableArmor::CreateObject(std::istream& is, Field* field, Cell* cell,
                                                std::map<std::string, DeserializableFactory*>* creator)
{
    return new ArmorItem(cell);
}
