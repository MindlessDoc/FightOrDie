#include "game.h"

Game::Game(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
{
    _graphicField = new GraphicField(heightOfCell, widthOfCell, heightInCells, widthInCells);
    _player = new Player(100, 100, 100);
    _graphicField->InitGraphicField(_player);
    _mainWindow = new MainWindow(heightOfCell, widthOfCell, heightInCells, widthInCells, _graphicField, _player);
}

void Game::Start()
{
    _mainWindow->show();
}
