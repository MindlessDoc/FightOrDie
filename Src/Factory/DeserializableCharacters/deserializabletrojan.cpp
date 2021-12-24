#include "deserializabletrojan.h"

Serializable* DeserializableTrojan::CreateObject(std::istream &is, Field *field, Cell *cell)
{
    return new Trojan(field, cell);
}

