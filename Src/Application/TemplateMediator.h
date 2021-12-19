#pragma once

#include "mediator.h"
#include "Src/Fields/graphicfield.h"
#include "Src/Application/mainwindow.h"
#include "Src/Entities/Characters/Player/player.h"
#include "Src/Controller/controller.h"

template<class LogRule, class EnemySpawn>
class TemplateMediator : public Mediator
{
public:
    TemplateMediator()
        : _graphicField(nullptr)
    {

    }
    void InitMediator(GraphicField* graphicField, Player* player, MainWindow* mainWindow, Controller* controller)
    {
        _graphicField = graphicField;
        _player = player;
        _logRule.AddInLogger(_player);
        _mainWindow = mainWindow;
        _controller = controller;
    }

    void UpdateMediator(GraphicField* graphicField, Player* player, MainWindow* mainWindow, Controller* controller)
    {

    }

    virtual void DoSpawnEnemy(Field* field) override
    {
        _enemySpawn.Spawn(field, this);
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

    virtual void notifyController(int pressedKey)
    {
        _controller->KeyIsPressed(pressedKey);
    }


private:
    GraphicField* _graphicField;
    Player* _player;
    MainWindow* _mainWindow;
    Controller* _controller;

    LogRule _logRule;
    EnemySpawn _enemySpawn;
};
