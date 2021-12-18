#pragma once
#include <QApplication>
#include "Application/mainwindow.h"
#include "mediator.h"
#include "Controller/controller.h"
#include "gameobjects.h"

#include "Loggers/logger.h"
#include "Memento/originator.h"

class Game : public Originator
{
public:
    Game(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells);
    ~Game();

    void  Start();

    virtual void Save();
    virtual void Download(Memento* memento);
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

