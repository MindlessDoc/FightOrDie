#include "loggable.h"
#include "Src/Entities/Characters/Player/player.h"

Loggable::Loggable()
{

}

Loggable::~Loggable()
{

}

void Loggable::AddLogger(Logger *logger)
{
    _loggers.push_back(logger);
}

void Loggable::notify()
{
    for(size_t i = 0; i < _loggers.size(); i++)
    {
        _loggers[i]->Update(this);
    }
}

std::string Loggable::LogOut() const
{
    return "Nothing";
}

std::ostream& operator<<(std::ostream& out, const Loggable &loggable)
{
    return out << loggable.LogOut();
}


