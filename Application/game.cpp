#include "game.h"
#include "Loggers/ConsolLogger/consollogger.h"
#include "Loggers/FileLogger/filelogger.h"
#include "TemplateMediator.h"
#include "Rules/LoggerRule/loggerrule.h"

Game::Game(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
{

    _mediator = new TemplateMediator<LoggerRule<true, false>>();

    //_logger = new FileLogger();

    _field = new Field(heightInCells, widthInCells);

    _player = new Player(100, 100, 100, _mediator);
    //_logger->AddInLogger(_player);


    _field->InitField(_player, _mediator);

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
