#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "ui_mainwindow.h"

#include "Fields/graphicfield.h"
#include <QTimer>
#include <QTime>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells,
               GraphicField* _graphicField, Player* _player, Mediator* mediator, QWidget *parent = 0);
    virtual ~MainWindow();

    void DrawField(QGraphicsItem* graphicfield);

    void CloseWindow();

    void PlayerInfoHealthUpdate(int health);
    void PlayerInfoAttackUpdate(int attack);
    void PlayerInfoArmorUpdate(int armor);

public slots:   
    void FrameUpdate();


protected:
    virtual void keyPressEvent(QKeyEvent *event) override;

private:    
    const int _sizeOfPlayerAvatar = 100;
    const int _sizeOfIcons = 25;
    void InitInterface(Player* player);

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    Mediator* _mediator;

    int _height;
    int _width;

    //GraphicField _graphicField;

    QTimer* _timer;
    int _frameUpdateTime;
};
