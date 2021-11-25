#include "consollogger.h"
#include <iostream>
#include "Loggable/loggable.h"

#include "Entities/Characters/Player/player.h"

ConsolLogger::ConsolLogger()
{

}

void ConsolLogger::Update(Loggable *loggable)
{
    std::cout << *loggable;
}
