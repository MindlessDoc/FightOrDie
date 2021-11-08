#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include "QGraphicsItem"
#include "ui_mainwindow.h"
#include "Fields/graphicfield.h"
#include "QTimer"
#include "QTime"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells, QWidget *parent = nullptr);
    virtual ~MainWindow();

    void DrawField(QGraphicsItem* graphicfield);

public slots:
    void DoCloseWindow();
    void FrameUpdate();

signals:
    void MovingPlayerSignal(int x, int y);

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int _height;
    int _width;

    GraphicField _graphicField;

    QTimer* _timer;
    int _frameUpdateTime;
};
