#include "mainwindow.h"


MainWindow::MainWindow(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _height(heightOfCell * heightInCells)
    , _width(widthOfCell * widthInCells)
    , _graphicField(heightOfCell, widthOfCell, heightInCells, widthInCells)
{
    ui->setupUi(this);

    setFixedSize(_width + 20, _height + 20);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, _width, _height);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setWindowTitle("Game field");
    DrawField(&_graphicField);
}


void MainWindow::DrawField(QGraphicsItem* graphicfield)
{
    scene->addItem(graphicfield);
}

MainWindow::~MainWindow()
{
    delete ui;
}

