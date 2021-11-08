#include "mainwindow.h"

#include <QApplication>
#include "Application/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow(50, 50, 10, 20);
    mainWindow.show();
    return a.exec();
}
