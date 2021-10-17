#include "mainwindow.h"

#include <QApplication>
#include "Application/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow(70, 70, 8, 5);
    mainWindow.show();
    return a.exec();
}
