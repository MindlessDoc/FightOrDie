#include "deserializableattack.h"

Serializable* DeserializableAttack::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    return new AttackItem(cell);
}

