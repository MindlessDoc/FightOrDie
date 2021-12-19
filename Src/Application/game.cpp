#include "game.h"
#include "Src/Loggers/ConsolLogger/consollogger.h"
#include "Src/Loggers/FileLogger/filelogger.h"
#include "TemplateMediator.h"

#include "Src/Rules/LoggerRule/loggerrule.h"

#include "Src/Rules/EnemySpawnRule/enemyspawnrule.h"
#include "Src/ChooseCell/QtRandomChooseCell/qtrandomchoosecell.h"

#include "Src/Entities/Characters/Enemies/virus.h"
#include "Src/Entities/Characters/Enemies/trojan.h"
#include "Src/Entities/Characters/Enemies/immortal.h"

#include "Src/Controller/QtController/qtcontroller.h"


Game::Game(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
{

    _mediator = new TemplateMediator<LoggerRule<false, true>,
            EnemySpawnRule<QtRandomChooseCell, Virus, 2, Trojan, 1, Immortal, 1,
            LoggerRule<true, true>>>();

    _field = new Field(heightInCells, widthInCells);


    _player = new Player(100, 100, 100, _mediator);


    _field->InitField(_player, _mediator);
    _mediator->DoSpawnEnemy(_field);

    _graphicField = new GraphicField(_field, heightOfCell, widthOfCell);

    _mainWindow = new MainWindow(heightOfCell, widthOfCell, heightInCells, widthInCells, _graphicField, _player, _mediator);

    _controller = new QtController(_mediator);

    _mediator->InitMediator(_graphicField, _player, _mainWindow, _controller);

    _gameObjects = new GameObjects(_field, _player);
}

Game::~Game()
{
    delete _mainWindow;
    //delete _player; //DANGLING POINTER - FIX!!!
    delete _graphicField;
    delete _controller;
}

void Game::Start()
{
    _mainWindow->show();
}

void Game::Save()
{
    //_gameObjects = memento->GetGameObjects();
}


void Game::Download(Memento *memento)
{
    _gameObjects = memento->GetGameObjects();
    _field = _gameObjects->GetField();
    _player = _gameObjects->GetPlayer();
}

Mediator* Game::GetMediator() { return _mediator; }
