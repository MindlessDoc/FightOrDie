#include "deserializableimmortal.h"

Serializable* DeserializableImmortal::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    return new Immortal(field, cell);
}
