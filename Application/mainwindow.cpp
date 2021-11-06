#include "mainwindow.h"


MainWindow::MainWindow(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _height(heightOfCell * heightInCells)
    , _width(widthOfCell * widthInCells)
    , _graphicField(heightOfCell, widthOfCell, heightInCells, widthInCells, this)
{
    ui->setupUi(this);

    setFixedSize(_width + 20, _height + 20);

    QObject::connect(this, &MainWindow::MovingPlayer, &_graphicField, &GraphicField::MovingPlayer);

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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_S: emit MovingPlayer(0, 1); break;
    case Qt::Key_W: emit MovingPlayer(0, -1); break;
    case Qt::Key_A: emit MovingPlayer(-1, 0); break;
    case Qt::Key_D: emit MovingPlayer(1, 0); break;
    }
    scene->update();
}
