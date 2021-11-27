#pragma once

class Cell;
class GraphicField;
class Player;
class MainWindow;

class Mediator
{
public:
    //Mediator();
    virtual void InitMediator(GraphicField* graphicField, Player* player, MainWindow* mainWindow) = 0;

    virtual void notifySwap(Cell* first, Cell* second) = 0;
    virtual void notifyGameOver() = 0;
    virtual void notifyPlayerMove(int x, int y) = 0;
    virtual void notifyPlayerHealthChange(int health) = 0;
    virtual void notifyPlayerArmorChange(int armor) = 0;
    virtual void notifyPlayerAttackChange(int attack) = 0;
    virtual void notifyDeleteEntity(int column, int row) = 0;

//private:
//    GraphicField* _graphicField;
//    Player* _player;
//    MainWindow* _mainWindow;
};
