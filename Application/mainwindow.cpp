#include "mainwindow.h"


MainWindow::MainWindow(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _height(heightOfCell * heightInCells)
    , _width(widthOfCell * widthInCells)
    , _graphicField(heightOfCell, widthOfCell, heightInCells, widthInCells)
    , _frameUpdateTime(20)
{
    ui->setupUi(this);
    setFixedSize(_width + 20, _height + _sizeOfPlayerAvatar + _sizeOfIcons * 3);

    connect(this, &MainWindow::MovingPlayerSignal, &_graphicField, &GraphicField::MovingPlayerSlot);
    connect(&_graphicField, &GraphicField::DoCloseWindow, this, &MainWindow::DoCloseWindow);

    connect(_graphicField.GetPlayer(), &Player::HealthChange, this, &MainWindow::PlayerInfoHealthUpdate);
    connect(_graphicField.GetPlayer(), &Player::AttackChange, this, &MainWindow::PlayerInfoAttackUpdate);
    connect(_graphicField.GetPlayer(), &Player::ArmorChange, this, &MainWindow::PlayerInfoArmorUpdate);

    _timer = new QTimer();
    connect(_timer, &QTimer::timeout, this, &MainWindow::FrameUpdate);
    _timer->start(_frameUpdateTime);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, _width, _height);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    InitInterface();

    DrawField(&_graphicField);
}
MainWindow::~MainWindow()
{
    delete _timer;
    delete ui;
}

void MainWindow::InitInterface()
{
    QPixmap avatar("C:/QtProjects/OOP/FightOrDie/Src/Player.png");
    ui->playerAvatar->setPixmap(avatar.scaled(_sizeOfPlayerAvatar, _sizeOfPlayerAvatar));

    const Player* additional = _graphicField.GetPlayer();

    QPixmap health("C:/QtProjects/OOP/FightOrDie/Src/HealthIcon.png");
    ui->staticHealth->setPixmap(health.scaled(_sizeOfIcons, _sizeOfIcons));
    ui->healthText->setText(QString::number(additional->GetHealth()));

    QPixmap attack("C:/QtProjects/OOP/FightOrDie/Src/AttackIcon.png");
    ui->staticAttack->setPixmap(attack.scaled(_sizeOfIcons, _sizeOfIcons));
    ui->attackText->setText(QString::number(additional->GetAttack()));

    QPixmap armor("C:/QtProjects/OOP/FightOrDie/Src/ArmorIcon.png");
    ui->staticArmor->setPixmap(armor.scaled(_sizeOfIcons, _sizeOfIcons));
    ui->armorText->setText(QString::number(additional->GetArmor()));

    setWindowTitle("Game field");
}

void MainWindow::DrawField(QGraphicsItem* graphicfield)
{
    scene->addItem(graphicfield);
}

void MainWindow::DoCloseWindow()
{
    close();
}

void MainWindow::FrameUpdate()
{
    scene->update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_S: emit MovingPlayerSignal(0, 1); break;
    case Qt::Key_W: emit MovingPlayerSignal(0, -1); break;
    case Qt::Key_A: emit MovingPlayerSignal(-1, 0); break;
    case Qt::Key_D: emit MovingPlayerSignal(1, 0); break;
    }
    //scene->update();
}

void MainWindow::PlayerInfoHealthUpdate(int health)
{
    ui->healthText->setText(QString::number(health));
}

void MainWindow::PlayerInfoAttackUpdate(int attack)
{
    ui->attackText->setText(QString::number(attack));
}

void MainWindow::PlayerInfoArmorUpdate(int armor)
{
    ui->armorText->setText(QString::number(armor));
}
