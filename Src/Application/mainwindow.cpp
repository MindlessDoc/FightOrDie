#include "mainwindow.h"
#include "Src/Application/mediator.h"


MainWindow::MainWindow(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells,
                       GraphicField* graphicField, Player* player, Mediator* mediator, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _mediator(mediator)
    , _height(heightOfCell * heightInCells)
    , _width(widthOfCell * widthInCells)
    , _frameUpdateTime(20)
{
    ui->setupUi(this);
    setFixedSize(_width + 20, _height + _sizeOfPlayerAvatar + _sizeOfIcons * 3);

    _timer = new QTimer();
    connect(_timer, &QTimer::timeout, this, &MainWindow::FrameUpdate);
    _timer->start(_frameUpdateTime);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, _width, _height);
    //ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    InitInterface(player);

    DrawField(graphicField);
}
MainWindow::~MainWindow()
{
    delete _timer;
    delete ui;
}

void MainWindow::InitInterface(Player* player)
{
    QPixmap avatar("C:/QtProjects/OOP/FightOrDie/Resources/Src/Player.png");
    ui->playerAvatar->setPixmap(avatar.scaled(_sizeOfPlayerAvatar, _sizeOfPlayerAvatar));

    QPixmap health("C:/QtProjects/OOP/FightOrDie/Resources/Src/HealthIcon.png");
    ui->staticHealth->setPixmap(health.scaled(_sizeOfIcons, _sizeOfIcons));
    ui->healthText->setText(QString::number(player->GetHealth()));

    QPixmap attack("C:/QtProjects/OOP/FightOrDie/Resources/Src/AttackIcon.png");
    ui->staticAttack->setPixmap(attack.scaled(_sizeOfIcons, _sizeOfIcons));
    ui->attackText->setText(QString::number(player->GetAttack()));

    QPixmap armor("C:/QtProjects/OOP/FightOrDie/Resources/Src/ArmorIcon.png");
    ui->staticArmor->setPixmap(armor.scaled(_sizeOfIcons, _sizeOfIcons));
    ui->armorText->setText(QString::number(player->GetArmor()));

    setWindowTitle("Game field");
}

void MainWindow::DrawField(QGraphicsItem* graphicfield)
{
    scene->addItem(graphicfield);
}

void MainWindow::CloseWindow()
{
    close();
}

void MainWindow::FrameUpdate()
{
    scene->update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    _mediator->notifyController(event->key());
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
