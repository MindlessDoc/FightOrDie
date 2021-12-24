#include "deserializableattack.h"

Serializable* DeserializableAttack::CreateObject(std::istream& is, Field* field, Cell* cell,
                                                 std::map<std::string, DeserializableFactory*>* creator)
{
    return new AttackItem(cell);
}

