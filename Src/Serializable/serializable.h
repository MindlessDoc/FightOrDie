#pragma once
#include <iostream>

class Serializable
{
protected:
    ~Serializable() = default;

public:
    virtual void Serialize(std::ostream& os) = 0;
};
