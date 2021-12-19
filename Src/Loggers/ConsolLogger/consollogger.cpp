#include "consollogger.h"
#include <iostream>
#include "Src/Loggable/loggable.h"

#include "Src/Entities/Characters/Player/player.h"

ConsolLogger::ConsolLogger()
{

}

void ConsolLogger::Update(Loggable *loggable)
{
    std::cout << *loggable;
}
