#pragma once

class Cell;
class GraphicField;
class Field;
class Player;
class MainWindow;
class Controller;
class Caretaker;

class Mediator
{
public:
    //Mediator();
    virtual void InitMediator(GraphicField* graphicField, Player* player,
                              MainWindow* mainWindow, Controller* controller) = 0;
    virtual void InitCaretaker(Caretaker* caretaker) = 0;
    virtual void DoSpawnEnemy(Field* field) = 0;

    virtual void notifySwap(Cell* first, Cell* second) = 0;
    virtual void notifyGameOver() = 0;
    virtual void notifyPlayerMove(int x, int y) = 0;
    virtual void notifyPlayerHealthChange(int health) = 0;
    virtual void notifyPlayerArmorChange(int armor) = 0;
    virtual void notifyPlayerAttackChange(int attack) = 0;
    virtual void notifyDeleteEntity(int column, int row) = 0;
    virtual void notifyController(int pressedKey) = 0;

    virtual void notifyCaretakerSave() = 0;
    virtual void notifyCaretakerDownload() = 0;

//private:
//    GraphicField* _graphicField;
//    Player* _player;
//    MainWindow* _mainWindow;
};
