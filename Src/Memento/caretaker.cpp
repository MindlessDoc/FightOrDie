#include "caretaker.h"

//Caretaker::Caretaker(Originator* originator, std::string pathOfLoggs)
//    :_originator(originator)
//{
//    for(size_t i = 0; i < _countOfSaving; i++)
//    {
//        std::string fullFileName = pathOfLoggs + "/" + _savingFileName + std::to_string(i);
//        std::ifstream fin(fullFileName);
//        if(fin.is_open())
//        {
//            _downloads.push_back(new Memento(fullFileName));
//        }
//        else
//        {
//            continue;
//        }
//    }
//}

Caretaker::Caretaker(Originator* originator, std::string pathOfLoggs)
    : _savingPath(pathOfLoggs)
    , _originator(originator)
{

}

void Caretaker::DoSave()
{
    _originator->Save();
}

void Caretaker::DoDownload(int index)
{
    std::string fullFileName = _savingPath + "/" + _savingFileName + std::to_string(index);
    std::ifstream fin(fullFileName);
    if(fin.is_open())
    {
        _originator->Download(new Memento(fullFileName, _originator->GetCreator()));
    }
    else
    {
        std::cout << "Haven't this saving" << std::endl;
    }
}
