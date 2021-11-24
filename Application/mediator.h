#pragma once

class Cell;
class GraphicField;
class Player;
class MainWindow;

class Mediator
{
public:
    Mediator();
    void InitMediator(GraphicField* graphicField, Player* player, MainWindow* mainWindow);

    virtual void notifySwap(Cell* first, Cell* second);
    virtual void notifyGameOver();
    virtual void notifyPlayerMove(int x, int y);
    virtual void notifyPlayerHealthChange(int health);
    virtual void notifyPlayerArmorChange(int armor);
    virtual void notifyPlayerAttackChange(int attack);

private:
    GraphicField* _graphicField;
    Player* _player;
    MainWindow* _mainWindow;
};
