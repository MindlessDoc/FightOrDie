#include "mainwindow.h"

#include <QApplication>
#include"field.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Field field(5, 5);
    return a.exec();
}
