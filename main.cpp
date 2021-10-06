#include "mainwindow.h"

#include <QApplication>
#include"field.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Field field(2, 15);
    return a.exec();
}
