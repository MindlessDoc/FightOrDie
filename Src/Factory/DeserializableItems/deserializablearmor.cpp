#include "deserializablearmor.h"

Serializable* DeserializableArmor::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    return new ArmorItem(cell);
}
