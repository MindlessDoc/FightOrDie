#pragma once
#include "memento.h"

class Originator
{
public:
    virtual void Save() = 0;
    virtual void Download(Memento* memento) = 0;
};
