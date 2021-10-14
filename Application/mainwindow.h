#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "QGraphicsItem"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int height, int width, QWidget *parent = nullptr);
    ~MainWindow();
    void DrawField(QGraphicsItem* graphicfield);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    const int _height;
    const int _width;
};
#endif // MAINWINDOW_H
