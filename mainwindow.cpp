#include "mainwindow.h"


MainWindow::MainWindow(int height, int width,  QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _width = width;
    _height = height;

    this->setFixedSize(_width + 20, _height + 20);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, _width, _height);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


void MainWindow::DrawField(QGraphicsItem* graphicfield)
{
    scene->addItem(graphicfield);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

