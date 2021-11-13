#pragma once
#include <QApplication>
#include "Application/mainwindow.h"
#include "Fields/graphicfield.h"

class Game
{
public:
    Game(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    ~Game();

    void  Start();
private:
    GraphicField* _graphicField;
    Player* _player;
    MainWindow* _mainWindow;
};

