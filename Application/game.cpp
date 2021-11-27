#include "game.h"
#include "Loggers/ConsolLogger/consollogger.h"
#include "Loggers/FileLogger/filelogger.h"
#include "TemplateMediator.h"

#include "Rules/LoggerRule/loggerrule.h"

#include "Rules/EnemySpawnRule/enemyspawnrule.h"
#include "ChooseCell/QtRandomChooseCell/qtrandomchoosecell.h"

#include "Entities/Characters/Enemies/virus.h"
#include "Entities/Characters/Enemies/trojan.h"
#include "Entities/Characters/Enemies/immortal.h"


Game::Game(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
{

    _mediator = new TemplateMediator<LoggerRule<false, true>,
            EnemySpawnRule<QtRandomChooseCell, Virus, 1, Trojan, 1, Immortal, 1,
            LoggerRule<true, true>>>();

    _field = new Field(heightInCells, widthInCells);


    _player = new Player(100, 100, 100, _mediator);


    _field->InitField(_player, _mediator);
    _mediator->DoSpawnEnemy(_field);

    _graphicField = new GraphicField(_field, heightOfCell, widthOfCell);

    _mainWindow = new MainWindow(heightOfCell, widthOfCell, heightInCells, widthInCells, _graphicField, _player, _mediator);

    _mediator->InitMediator(_graphicField, _player, _mainWindow);
}

Game::~Game()
{
    delete _mainWindow;
    //delete _player; //DANGLING POINTER - FIX!!!
    delete _graphicField;
}

void Game::Start()
{
    _mainWindow->show();
}
