#include "logger.h"
#include "Loggable/loggable.h"

void Logger::AddInLogger(Loggable *loggable)
{
    loggable->AddLogger(this);
}
