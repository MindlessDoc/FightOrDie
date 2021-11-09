#include "mainwindow.h"

#include <QApplication>
#include "Application/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow(100, 100, 7, 10);
    mainWindow.show();
    return a.exec();
}
