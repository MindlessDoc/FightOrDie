#include "filelogger.h"
#include "Loggable/loggable.h"

FileLogger::FileLogger(std::string filename)
    :_filename(filename)
{
    _out.open("C:/QtProjects/OOP/FightOrDie/logout.txt");
    //_out.clear();

    try
    {
        if(!_out.is_open())
        {
            throw "Can't open file";
        }
    }
    catch (char const* exception)
    {
        std::cout << "Error: " << exception << std::endl;
    }
}

FileLogger::~FileLogger()
{
    _out.close();
}

void FileLogger::Update(Loggable *loggable)
{
    _out << *loggable;
}
