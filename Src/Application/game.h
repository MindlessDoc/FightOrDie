#pragma once
#include <QApplication>
#include "Src/Application/mainwindow.h"
#include "mediator.h"
#include "Src/Controller/controller.h"
#include "gameobjects.h"

#include "Src/Loggers/logger.h"
#include "Src/Memento/originator.h"

class Game : public Originator
{
public:
    Game(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    ~Game();

    void  Start();

    virtual void Save();
    virtual void Download(Memento* memento);

    Mediator* GetMediator();
private:
    Field* _field;
    GraphicField* _graphicField;
    Player* _player;
    MainWindow* _mainWindow;
    Mediator* _mediator;
    Controller* _controller;

    GameObjects* _gameObjects;

    //Logger* _logger;
};

