#include "mainwindow.h"

#include "Application/game.h"

#include <QApplication>
#include "Application/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game(100, 100, 7, 10);
    game.Start();
    return a.exec();
}
