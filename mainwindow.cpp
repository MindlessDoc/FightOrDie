#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsScene>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->addLine(0, 0, 100, 0, QPen(Qt::black, 5.0));
    scene->addLine(0, 0, 0, 100, QPen(Qt::black, 2.0));

}

MainWindow::~MainWindow()
{
    delete ui;
}

