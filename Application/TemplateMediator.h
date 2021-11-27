#pragma once

#include "mediator.h"
#include "Fields/graphicfield.h"
#include "Application/mainwindow.h"
#include "Entities/Characters/Player/player.h"

template<class LogRule>
class TemplateMediator : public Mediator
{
public:
    TemplateMediator()
        : _graphicField(nullptr)
    {

    }
    void InitMediator(GraphicField* graphicField, Player* player, MainWindow* mainWindow)
    {
        _graphicField = graphicField;
        _player = player;
        _logRule.AddInLogger(_player);
        _mainWindow = mainWindow;
    }

    virtual void notifySwap(Cell* first, Cell* second)
    {
        _graphicField->GetGraphicCell(first->GetColumn(),
                                      first->GetRow())->EntitySwap(_graphicField->GetGraphicCell(second->GetColumn(),
                                                                                               second->GetRow()));
    }

    virtual void notifyGameOver()
    {
        //add  clearing memory
        _mainWindow->CloseWindow();
    }

    virtual void notifyPlayerMove(int x, int y)
    {
        _player->Move(x, y);
    }


    virtual void notifyPlayerHealthChange(int health)
    {
        _mainWindow->PlayerInfoHealthUpdate(health);
    }


    virtual void notifyPlayerArmorChange(int armor)
    {
        _mainWindow->PlayerInfoArmorUpdate(armor);
    }

    virtual void notifyPlayerAttackChange(int attack)
    {
        _mainWindow->PlayerInfoAttackUpdate(attack);
    }

    virtual void notifyDeleteEntity(int column, int row)
    {
        _graphicField->GetGraphicCell(column, row)->DeleteGraphicEntity();
    }


private:
    GraphicField* _graphicField;
    Player* _player;
    MainWindow* _mainWindow;

    LogRule _logRule;
};
