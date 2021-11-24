#include "mediator.h"

#include "Fields/graphicfield.h"
#include "Application/mainwindow.h"
#include "Entities/Characters/Player/player.h"

Mediator::Mediator()
    : _graphicField(nullptr)
{

}

void Mediator::InitMediator(GraphicField* graphicField, Player* player, MainWindow* mainWindow)
{
    _graphicField = graphicField;
    _player = player;
    _mainWindow = mainWindow;
}

void Mediator::notifySwap(Cell *first, Cell *second)
{
    _graphicField->GetGraphicCell(first->GetColumn(),
                                  first->GetRow())->EntitySwap(_graphicField->GetGraphicCell(second->GetColumn(),
                                                                                           second->GetRow()));
}

void Mediator::notifyGameOver()
{
    //add  clearing memory
    _mainWindow->CloseWindow();
}

void Mediator::notifyPlayerMove(int x, int y)
{
    _player->Move(x, y);
}

void Mediator::notifyPlayerArmorChange(int armor)
{
    _mainWindow->PlayerInfoArmorUpdate(armor);
}

void Mediator::notifyPlayerAttackChange(int attack)
{
    _mainWindow->PlayerInfoAttackUpdate(attack);
}

void Mediator::notifyPlayerHealthChange(int health)
{
    _mainWindow->PlayerInfoHealthUpdate(health);
}

void Mediator::notifyDeleteEntity(int column, int row)
{
    _graphicField->GetGraphicCell(column, row)->DeleteGraphicEntity();
}
