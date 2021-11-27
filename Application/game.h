#pragma once
#include <QApplication>
#include "Application/mainwindow.h"
#include "Fields/graphicfield.h"
#include "mediator.h"

#include "Loggers/logger.h"

class Game
{
public:
    Game(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    ~Game();

    void  Start();
private:
    Field* _field;
    GraphicField* _graphicField;
    Player* _player;
    MainWindow* _mainWindow;
    Mediator* _mediator;

    //Logger* _logger;
};

