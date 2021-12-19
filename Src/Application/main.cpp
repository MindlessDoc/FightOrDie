#include "mainwindow.h"

#include "Src/Application/game.h"

#include <QApplication>
#include "Src/Application/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game(100, 100, 7, 10);
    game.Start();
    return a.exec();
}
