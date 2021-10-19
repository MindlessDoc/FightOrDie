#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include "QGraphicsItem"
#include "ui_mainwindow.h"
#include "Fields/graphicfield.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells, QWidget *parent = nullptr);
    ~MainWindow();

    void DrawField(QGraphicsItem* graphicfield);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int _height;
    int _width;

    GraphicField _graphicField;
};
