#include "logger.h"
#include "Src/Loggable/loggable.h"

void Logger::AddInLogger(Loggable *loggable)
{
    loggable->AddLogger(this);
}
