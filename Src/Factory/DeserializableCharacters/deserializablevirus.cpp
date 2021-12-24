#include "deserializablevirus.h"

Serializable* DeserializableVirus::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    return new Virus(field, cell);
}
