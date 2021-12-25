#include "deserializableimmortal.h"

Serializable* DeserializableImmortal::CreateObject(std::istream& is, Field* field, Cell* cell,
                                                   std::map<std::string, DeserializableFactory*>* creator)
{

    return new Immortal(field, cell);
}
