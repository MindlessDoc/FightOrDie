#pragma once
#include "originator.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Caretaker
{
public:
    Caretaker(Originator* originator, std::string pathOfLoggs);

    void DoSave();
    void DoDownload(int index);
private:
    const size_t _countOfSaving = 10;

    std::string _savingPath;
    const std::string _savingFileName = "saving";

    Originator* _originator;
    //std::vector<Memento*> _downloads;
};
