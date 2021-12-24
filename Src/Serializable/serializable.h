#pragma once
#include <iostream>

#include "Src/Factory/serializablefactory.h"

class Serializable
{
protected:
    ~Serializable() = default;
private:
    SerializableFactory* _serializableFactory;

public:
//    virtual void Serialize(std::ostream& os);
//    virtual void Deserialize(std::istream& is);
};
