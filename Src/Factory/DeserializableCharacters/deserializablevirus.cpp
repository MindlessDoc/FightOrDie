#include "deserializablevirus.h"

Serializable* DeserializableVirus::CreateObject(std::istream& is, Field* field, Cell* cell,
                                                std::map<std::string, DeserializableFactory>* creator)
{
    return new Virus(field, cell);
}
