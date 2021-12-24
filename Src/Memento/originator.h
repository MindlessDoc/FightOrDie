#pragma once
#include "memento.h"
#include <map>
#include "Src/Factory/deserializablefactory.h"

class Originator
{
private:
    std::map<std::string, DeserializableFactory*>* _creator = nullptr;
public:
    virtual void Save(std::ofstream& out) = 0;
    virtual void Download(Memento* memento) = 0;

    void SetCreator(std::map<std::string, DeserializableFactory*>*);
    std::map<std::string, DeserializableFactory*>* GetCreator();
};
