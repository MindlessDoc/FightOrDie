#include "originator.h"

void Originator::SetCreator(std::map<std::string, DeserializableFactory*>* creator)
{
    _creator = creator;
}
std::map<std::string, DeserializableFactory*>* Originator::GetCreator() { return _creator; }
